<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('Interior: 1'),
  'category' => t('AR Distro'),
  'icon' => 'interior1.png',
  'theme' => 'panels_interior1',
  'theme arguments' => array('id', 'content'),
  'css' => 'interior1.css',
  'regions' => array(
    'destacado' => t('Imagen destacada o carousel'),
    'atajos' => t('Atajos'),
    'novedades' => t('Novedades'),
    'main' => t('Principal'),
  ),
);