<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('Página de inicio'),
  'category' => t('AR Distro'),
  'icon' => 'inicio.png',
  'theme' => 'panels-inicio',
  'theme arguments' => array('id', 'content'),
  'css' => 'inicio.css',
  'regions' => array(
    'destacado' => t('Imagen destacada o carousel'),
    'atajos' => t('Atajos'),
    'novedades' => t('Novedades'),
    'enlaces' => t('Enlaces'),
  ),
);

