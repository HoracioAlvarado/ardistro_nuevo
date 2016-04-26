<?php

$plugin = array(
    'single' => TRUE,
    'title' => t('Imagen Destacada Home'),
    'description' => t('Imagen Destacada Home'),
    'category' => t('AR Distro'),
    'render callback' => 'ardistro_bloques_imagen_destacada_home_render',
    'edit form' => 'ardistro_bloques_imagen_destacada_home_edit_form',
    'admin info' => 'ardistro_bloques_imagen_destacada_home_info',
    'defaults' => array(
        'titulo' => '',
        'alt' => '',
        'bajada' => '',
        'tipos_de_link' => array(),
        'imagen' => '',
        'link' => '',
        'tipo_de_link' => 'all',
    )
);

/**
*  Hook para mostrar en el menu de ardistro
*/
function ardistro_bloques_imagen_destacada_home_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title 
        = $conf['override_title'] 
        ? $conf['override_title_text'] 
        : t('Imagen Destacada Home')
    ;

    $block->content = t('Imagen Destacada Home');
    return $block;
  }
}

function ardistro_bloques_imagen_destacada_home_edit_form($form, &$form_state) {

    form_load_include($form_state, 'inc', 'ardistro_bloques', 'plugins/content_types/imagen_destacada_home');

    $form['imagen'] = array(
        '#title' => t('Imagen'),
        '#type' => 'managed_file',        
        // '#description' => t('The uploaded image will be displayed on this page using the image style chosen below.'),
        '#default_value' => $form_state['conf']['imagen'],
        '#upload_location' => 'public://imagen_destacada_home/',
    );

    $form['alt'] = array(
        '#title' => t('Alt'),
        '#type' => 'textfield',
        '#default_value' => $form_state['conf']['alt'],
    );
    
    $form['titulo'] = array(
        '#title' => t('Titulo'),
        '#type' => 'textfield',
        '#default_value' => $form_state['conf']['titulo'],
    );

    $form['bajada'] = array(
        '#title' => t('Bajada'),
        '#type' => 'textarea',
        '#default_value' => $form_state['conf']['bajada'],
    );

    $form['link'] = array(
        '#title' => t('Link'),
        '#type' => 'textfield',
        '#default_value' => $form_state['conf']['link'],
    );

    $form['tipo_de_link'] = array(
        '#title' => t('Tipo de link'),
        '#type' => 'select',
        '#required' => FALSE,
        '#options' => array (
            "_blank" => t('Blank'),
            "_self" => t('Self'),
            "_parent" => t('Parent'),
            "_top" => t('Top'),
            "framename" => t('Frame Name')
        ),
        '#default_value' => $form_state['conf']['tipo_de_link'],
    );

    return $form;

}

function ardistro_bloques_imagen_destacada_home_edit_form_submit($form, &$form_state) {

    if ($form_state['values']['imagen'] != "") {
        // Load the file via file.fid.
        $file = file_load($form_state['values']['imagen']);
        // Change status to permanent.
        $file->status = FILE_STATUS_PERMANENT;
        // Save.
        file_save($file);
        // Record that the module (in this example, user module) is using the file. 
        file_usage_add($file, 'ardistro_bloques', 'imagen_destacada_home', $file->fid); 
    
        $form_state["conf"]["imagen"] = $file->fid;
    }
    

    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (isset($form_state['values'][$key])) {
            $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
}

function ardistro_bloques_imagen_destacada_home_render(
    $subtype, $conf, $panel_args, $context = NULL
) { 

    $img = entity_load('file', array($conf["imagen"]), array());
    $img = file_create_url($img[$conf["imagen"]]->uri);

    $block = new stdClass();
    $block->title = '';

    $block->content = theme(
        'ardistro_bloques_imagen_destacada_home',
        array(
            'titulo' => $conf['titulo'],
            'bajada' => $conf['bajada'],
            'alt' => $conf['alt'],
            'imagen' => $img,
            'link' => $conf['link'],
            'tipo_de_link' => $conf["tipo_de_link"]
        )
    );

    return $block;

}


