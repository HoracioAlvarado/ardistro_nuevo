<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Separador'),
  'description' => t('Crea un separador'),
  'category' => t('AR Distro'),
  'render callback' => 'ardistro_bloques_separador_render',
  'admin info' => 'ardistro_bloques_separador_admin_info',
  'defaults' => array()
);


/**
* 'admin info' callback for panel pane.
*/
function ardistro_bloques_separador_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Separador');
    $block->content = t('Separador');
    return $block;
  }
}
function ardistro_bloques_separador_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  $block->content = theme('ardistro_bloques_separador');
  return $block;
}