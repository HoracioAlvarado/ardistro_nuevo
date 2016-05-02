<?php

/**
 * hook_block_info()
 */
function ardistro_footer_block_info() {
  $blocks = array();
  $blocks['my_block'] = array(
    'info' => t('Bloque customizable para el footer'),
  );
  
  return $blocks;
}
