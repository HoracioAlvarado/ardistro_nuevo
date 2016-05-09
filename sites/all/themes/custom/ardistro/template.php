<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function ardistro_preprocess(&$variables, $hook) {
	// krumo($hook);
}

/**
 * THEME_preprocess_image_style() is also available.
 */
function ardistro_preprocess_image(&$variables) {
  if(isset($variables['style_name'])) {
    if($variables['style_name'] == 'articulo_thumbnail') {
      $variables['attributes']['class'][] = "img-thumbnail";
    }
  }
  //var_dump($variables);
}