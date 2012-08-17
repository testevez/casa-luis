<?php

/**
 * @file
 * CRUD functions for the Check Page module.
 */

function _check_page_add_checkpage($info) {
  $cpid = db_insert('check_page') // Table name no longer needs {}
  ->fields(array(
    'name' => $info['name'],
    'url' => $info['url'],
    'created' => REQUEST_TIME,
  ))
  ->execute();
  return $cpid;
}

function _check_page_load_pages() {
  // Get all the contact categories from the database.
  $pages = db_select('check_page', 'cp')
    ->fields('cp', array('cpid', 'name', 'url', 'created', 'checked', 'data', 'flag'))
    ->execute()
    ->fetchAll();
  return $pages;
}


function _check_page_update_page($page) {
  $num_updated = db_update('check_page') // Table name no longer needs {}
  ->fields(array(
    'checked' => REQUEST_TIME,
    'data' => $page->data,
    'flag' => $page->flag,
    'data' => $page->data,
  ))
  ->condition('cpid', $page->cpid, '=')
  ->execute();
}