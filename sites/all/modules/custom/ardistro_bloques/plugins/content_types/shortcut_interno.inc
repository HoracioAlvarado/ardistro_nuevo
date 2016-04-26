<?php


$plugin = array(
  'single' => TRUE,
  'title' => t('Atajo interno'),
  'description' => t('Crea un acceso directo en las páginas interiores'),
  'category' => t('AR Distro'),
  'render callback' => 'ardistro_bloques_shortcut_interno_render',
  'edit form' => 'ardistro_bloques_shortcut_interno_edit_form',
  'admin info' => 'ardistro_bloques_shortcut_interno_admin_info',
  'defaults' => array(
    'color_fondo' => 'shortcut-azul',
    'icono' => 'glyphicon-heart',
    'titulo' => '',
    'texto' => '',
    'link' => '',
    'formato' => '',
    )
);

/**
* 'admin info' callback for panel pane.
*/
function ardistro_bloques_shortcut_interno_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : $conf['titulo'];
    $block->content = $conf['texto'];
    return $block;
  }
}

/**
* 'Edit form' callback for the content type.
*/
function ardistro_bloques_shortcut_interno_edit_form($form, &$form_state) {
  $form['titulo'] = array(
    '#title' => t('Título'),
    '#type' => 'textfield',
    '#default_value' => $form_state['conf']['titulo'],
    '#required' => TRUE,
  );

  $form['texto'] = array(
    '#title' => t('Texto'),
    '#type' => 'textfield',
    '#default_value' => $form_state['conf']['texto'],
    '#required' => FALSE,
  );



  /* Define el tamaño de la columna */
  $form['color_fondo'] = array(
    '#title' => t('Color de fondo'),
    '#type' => 'select',
    '#default_value' => $form_state['conf']['color_fondo'],
    '#options' => array(
        'shortcut-base' => t('Base'),
      'shortcut-uno' => t('Verde agua'),
      'shortcut-dos' => t('Amarillo'),
      'shortcut-tres' => t('Naranja'),
      'shortcut-cuatro' => t('Violeta'),
      'shortcut-cinco' => t('azul'),
      'shortcut-seis' => t('Celeste'),
    ),
  );

  $form['icono'] = array(
    '#title' => t('Icono'),
    '#type' => 'select',
    '#default_value' => $form_state['conf']['icono'],
    '#options' =>  array(
	    "supervisor_account" => t("Desarrollo Social"),
            "supervisor_account" => t("Asistencia Social"),
            "today" => t("Calendario"),
            "explore" => t("Compás"),
            "mail" => t("Contacto"),
            "local_hospital" => t("Hospital"),
            "info" => t("Información útil"),
            "phone" => t("Teléfono"),
            "cast" => t("Cast"),
            "cast_connected" => t("Cast connected"),
            "computer" => t("Computer"),
            "desktop_mac" => t("Desktop mac"),
            "desktop_windows" => t("Desktop windows"),
            "developer_board" => t("Developer board"),
            "device_hub" => t("Device hub"),
            "devices_other" => t("Devices other"),
            "dock" => t("Dock"),
            "gamepad" => t("Gamepad"),
            "headset" => t("Headset"),
            "headset_mic" => t("Headset mic"),
            "keyboard" => t("Keyboard"),
            "keyboard_arrow_down" => t("Keyboard arrow down"),
            "keyboard_arrow_left" => t("Keyboard arrow left"),
            "keyboard_arrow_right" => t("Keyboard arrow right"),
            "keyboard_arrow_up" => t("Keyboard arrow up"),
            "keyboard_backspace" => t("Keyboard backspace"),
            "keyboard_capslock" => t("Keyboard capslock"),
            "keyboard_hide" => t("Keyboard hide"),
            "keyboard_return" => t("Keyboard return"),
            "keyboard_tab" => t("Keyboard tab"),
            "keyboard_voice" => t("Keyboard voice"),
            "laptop" => t("Laptop"),
            "laptop_chromebook" => t("Laptop chromebook"),
            "laptop_mac" => t("Laptop mac"),
            "laptop_windows" => t("Laptop windows"),
            "memory" => t("Memory"),
            "mouse" => t("Mouse"),
            "phone_android" => t("Phone android"),
            "phone_iphone" => t("Phone iphone"),
            "phonelink" => t("Phonelink"),
            "phonelink_off" => t("Phonelink off"),
            "power_input" => t("Power input"),
            "router" => t("Router"),
            "scanner" => t("Scanner"),
            "security" => t("Security"),
            "sim_card" => t("Sim card"),
            "smartphone" => t("Smartphone"),
            "speaker" => t("Speaker"),
            "speaker_group" => t("Speaker group"),
            "tablet" => t("Tablet"),
            "tablet_android" => t("Tablet android"),
            "tablet_mac" => t("Tablet mac"),
            "toys" => t("Toys"),
            "tv" => t("Tv"),
            "videogame_asset" => t("Videogame asset"),
            "watch" => t("Watch"),
        )

  );

  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link'),
    '#required' => FALSE,
    '#default_value' => $form_state['conf']['link'],
    '#description' => t('Usar este campo para crear un link personalizado'),
  );

  return $form;
}

/**
* The submit form stores the data in $conf.
*/
function ardistro_bloques_shortcut_interno_edit_form_submit($form, &$form_state) {

  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

}


function ardistro_bloques_shortcut_interno_render($subtype, $conf, $panel_args, $context = NULL){

  $block = new stdClass();
  $block->title = '';
  $block->content = !empty($conf['link']) ? l(
    theme(
      'ardistro_bloques_interno_shortcut',
      array(
        'color' => $conf['color_fondo'],
        'icono' => $conf['icono'],
        'texto' => $conf['texto'],
        'titulo' => $conf['titulo'],
        'css' => ''
      )
    ),
    $conf['link'],
    array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array(
          'col-sm-4',
          'col-md-6',
          'arg-shortcut'
        )
      ),
    )
  ) : theme(
      'ardistro_bloques_interno_shortcut',
      array(
        'color' => $conf['color_fondo'],
        'icono' => $conf['icono'],
        'texto' => $conf['texto'],
        //'imagen' => $imagen,
        'titulo' => $conf['titulo'],
        'css' => implode(' ', array(
          'col-sm-4',
          'col-md-6',
          'arg-shortcut',
          $conf['color_fondo']
          )
        )
      )
  );
  return $block;
}
