<?php

/**
 * @file
 * Theme callbacks for the Check Page module.
 */

function theme_check_page_pages_table($variables) {
  $pages = $variables['pages'];
  
  $header = array (
    'updated' => t('Status'),
    'name' => t('Name'),
    'url' => t('URL'),
    'last_checked' => t('Last Checked'),
    'link' => t('Link'),
  );
  // Initialize an empty array
  $options = array();
  // Next, loop through the $pages array
  dsm($pages);
  foreach ($pages as $i => $page) {
    $options[$page->cpid] = array( // each element of the array is keyed with the UID
      'updated' => ($page->flag ? 'Has been Updated' : 'Has not been Updated'),
      'name' => $page->name, // 'name' was the key used in the header
      'url' => $page->url, // 'url' was the key used in the header
      'last_checked' => format_date($page->checked),
      'link' => l('Go to page', $page->url, array('attributes' => array('target' => '_new'))),
    );
  }
  $output = array (
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
  );

  return $output;
}