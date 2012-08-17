<?php

/**
 * @file
 * Admin page callbacks for the Check Page module.
 */


function check_page_list_form() {
  
  $pages = _check_page_load_pages();
  $form['check_page_table'] = theme('check_page_pages_table', array('pages' => $pages));
  $form['pages'] = array(
    '#type' => 'hidden',
    '#value' => serialize($pages),
  );
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Mark as reviewed'),
  );
  $form['actions']['manual_check'] = array(
    '#type' => 'button', 
    '#value' => t('Check Pages'), 
  );
  return $form;
}


function check_page_list_form_submit($form, &$form_state) {
  
  $pages = unserialize($form_state['values']['pages']);
  
  _check_page_check_pages($pages);
}


function check_page_add_form() {
  
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#maxlength' => 255,
    '#description' => t("Name of the page to be checked"),
    '#required' => TRUE,
  );
  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#maxlength' => 255,
    '#description' => t("URL of the page to be checked"),
    '#required' => TRUE,
  );
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add Check Page'),
  );

  return $form;
}

function check_page_add_form_validate($form, &$form_state) {
  
  if (!$form_state['values']['url']) {
    form_set_error('url', 'You must supply a URL.');
  }

  return $form;
}
function check_page_add_form_submit($form, &$form_state) {
  $page = (object)$form_state['values'];
  
  $page->cpid = _check_page_add_checkpage($form_state['values']);
  _check_page_check_pages(array($page));
  drupal_goto(CHECK_PAGE_ADMIN_PATH);
  return $form;
}

