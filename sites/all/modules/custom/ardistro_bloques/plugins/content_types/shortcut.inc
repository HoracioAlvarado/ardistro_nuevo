<?php


$plugin = array(
  'single' => TRUE,
  'title' => t('Atajos'),
  'description' => t('Crea un acceso directo'),
  'category' => t('AR Distro'),
  'render callback' => 'ardistro_bloques_shortcut_render',
  'edit form' => 'ardistro_bloques_shortcut_edit_form',
  'admin info' => 'ardistro_bloques_shortcut_admin_info',
  'defaults' => array(
    'color_fondo' => 'shortcut-azul',
    'icono' => 'glyphicon-heart',
    'titulo' => '',
    'texto' => '',
    'link' => '',
    'col_size'=>'1',
    // 'file' => '',
    'formato' => '',
    )
);

/**
* 'admin info' callback for panel pane.
*/
function ardistro_bloques_shortcut_admin_info($subtype, $conf, $contexts) {
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
function ardistro_bloques_shortcut_edit_form($form, &$form_state) {
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

  $form['col_size'] = array(
    '#title' => t('Tamaño de columna'),
    '#type' => 'select',
    '#default_value' => $form_state['conf']['col_size'],
    '#options' => array (
        'Espacio simple' => array(
        1 => '1:4',
        2 => '1:3',
        3 => '1:6',
        10 => '1:5',
        ),
        'Espacio doble' => array(
        4 => '2:3',
        5 => '2:4',
        6 => '2:6',
        11 => '2:5',
        ),
        'Espacio triple' => array(
        7 => '3:3',
        8 => '3:4',
        9 => '3:6',
        12 => '3:5',
        ),
    ),
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
function ardistro_bloques_shortcut_edit_form_submit($form, &$form_state) {

  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  
}


function ardistro_bloques_shortcut_render($subtype, $conf, $panel_args, $context = NULL){
  
  $col = (int)$conf['col_size'];

  /* Define el tamaño de la columna */
  $colSize = array(
    1 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-3'),
    2 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-4'),
    3 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-2'),
    10 => array('sm'=> 'col-sm-6', 'md'=> 'ucol-md-2'),

    4 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-9'),
    5 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-6'),
    6 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-4'),
    11 => array('sm'=> 'col-sm-6', 'md'=> 'ucol-md-4'),

    7 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-12'),
    8 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-9'),
    9 => array('sm'=> 'col-sm-6', 'md'=> 'col-md-6'),
    12 => array('sm'=> 'col-sm-6', 'md'=> 'ucol-md-6'),
  );

  $block = new stdClass();
  $block->title = '';
  $block->content = !empty($conf['link']) ? l(
    theme(
      'ardistro_bloques_shortcut',
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
          $colSize[$conf['col_size']]['sm'],
          $colSize[$conf['col_size']]['md'],
          'arg-shortcut'
        )
      ),
    )
  ) : theme(
      'ardistro_bloques_shortcut',
      array(
        'color' => $conf['color_fondo'],
        'icono' => $conf['icono'],
        'texto' => $conf['texto'],
        'titulo' => $conf['titulo'],
        'css' => implode(' ', array(
          $colSize[$conf['col_size']]['sm'],
          $colSize[$conf['col_size']]['md'],
          'arg-shortcut',
          $conf['color_fondo']
          )
        )
      )
  );
  return $block;
}

