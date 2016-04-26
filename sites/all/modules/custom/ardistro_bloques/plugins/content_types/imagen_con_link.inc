<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Imagen con link'),
  'description' => t('Muestra una imagen con un link.'),
  'category' => t('AR Distro'),
  'render callback' => 'ardistro_bloques_imagen_con_link_render',
  'edit form' => 'ardistro_bloques_imagen_con_link_edit_form',
  'admin info' => 'ardistro_bloques_imagen_con_link_admin_info',
  'defaults' => array(
    'titulo' => '',
    'alt' => '',
    'tipos_de_link' => array(),
    'imagen' => '',
    'link' => '',
    'tipo_de_link' => 'all',
    'color_fondo' => '',

  )
);

/**
*  Hook para mostrar en el menu de ardistro
*/
function ardistro_bloques_imagen_con_link_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = !empty($conf['override_title']) ? $conf['override_title_text'] : t('Imagen con link');
    $block->content = t('Imagen con link');
    return $block;
  }
}

/*
*  Hook que arma el formulario
*/
function ardistro_bloques_imagen_con_link_edit_form($form, &$form_state) {
    
    form_load_include($form_state, 'inc', 'ardistro_bloques', 'plugins/content_types/imagen_con_link');
    $form['imagen'] = array(
        '#title' => t('Imagen'),
        '#type' => 'managed_file',        
        // '#description' => t('The uploaded image will be displayed on this page using the image style chosen below.'),
        '#default_value' => $form_state['conf']['imagen'],
        '#upload_location' => 'public://linked_images/',
    );

    $form['titulo'] = array(
        '#title' => t('Titulo'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#default_value' => $form_state['conf']['titulo'],
    );


    $form['alt'] = array(
        '#title' => t('Alt'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#default_value' => $form_state['conf']['alt'],
    );

    $form['link'] = array(
        '#title' => t('link'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#default_value' => $form_state['conf']['link'],
    );

    $form['tipo_de_link'] = array(
        '#title' => t('Tipo de link'),
        '#type' => 'select',
        '#required' => FALSE,
        '#default_value' => $form_state['conf']['tipo_de_link'],
        '#options' => array (
            "_blank" => t('Blank'),
            "_self" => t('Self'),
            "_parent" => t('Parent'),
            "_top" => t('Top'),
            "framename" => t('Frame Name')
        )
    );

    return $form;
}


/*
*  Hook que guarda la info del formulario en la DB
*/
function ardistro_bloques_imagen_con_link_edit_form_submit($form, &$form_state) {

    // Load the file via file.fid.
    $file = file_load($form_state['values']['imagen']);
    // Change status to permanent.
    $file->status = FILE_STATUS_PERMANENT;
    // Save.
    file_save($file);
    // Record that the module (in this example, user module) is using the file. 
    file_usage_add($file, 'ardistro_bloques', 'imagen_con_link', $file->fid); 

    $form_state["conf"]["imagen"] = $file->fid;

    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (isset($form_state['values'][$key])) {
            $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
    
}


/*
* Hook que pasa la info al template
*/
function ardistro_bloques_imagen_con_link_render($subtype, $conf, $panel_args, $context = NULL){

    $img = entity_load('file', array($conf["imagen"]), array());
    $img = file_create_url($img[$conf["imagen"]]->uri);
    
    $block = new stdClass();
    $block->title = '';

    $block->content = theme(
        'ardistro_bloques_imagen_con_link',
        array(
            'titulo' => $conf['titulo'],
            'alt' => $conf['alt'],
            'imagen' => $img,
            'link' => $conf['link'],
            'tipo_link' => $conf["tipo_de_link"]
        )
    );

    return $block;
}
