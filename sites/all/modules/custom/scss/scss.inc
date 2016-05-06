<?php

/**
 * hook_module_info()
 */
function scss_block_info() {
  $hook = array();
  $hook['scss'] = array(
    'info' => t('Modulo para customizar el css basico del sitio'),
  );
  
  return $hook;
}



function scss_permission() {
    return array(
        'administer scss settings' => array(
            'title' => t('Administer scss configurations'),
            'restrict access' => true,
        )
    );
}
