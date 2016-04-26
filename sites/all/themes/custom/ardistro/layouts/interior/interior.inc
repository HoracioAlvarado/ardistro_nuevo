<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('Interior'),
  'category' => t('AR Distro'),
  'icon' => 'interior.png',
  'theme' => 'panels-interior',
  'theme arguments' => array('id', 'content'),
  'css' => 'interior.css',
  'regions' => array(
    'destacado' => t('Imagen destacada o carousel'),
    'atajos' => t('Atajos'),
    'novedades' => t('Novedades'),
    'main' => t('Principal'),
  ),
);