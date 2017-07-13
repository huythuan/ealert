<?php
/**
 * @file
 * The setting form for ealert module.
 */


function ealert_page_form($form, &$form_state)
{
  $group_vid = taxonomy_vocabulary_machine_name_load('ealert_outreach_taxonomy')->vid;
  $taxonomies = taxonomy_get_tree($group_vid);
  $groupNames = array();
  $i = 0;
  foreach ($taxonomies as $taxonomy) {
    $groupNames[$i]['name'] = $taxonomy->name;
    $groupNames[$i]['machine_name'] = preg_replace('@[^a-z0-9-]+@','_', strtolower($taxonomy->name));
    $i++;
  }
   foreach ($groupNames as $group) {
        $form[$group['machine_name'] . '_fieldset'] = array(
            '#type' => 'fieldset',
	    '#title' => t($group['name']),
	    '#collapsible' => TRUE, // Added
	    '#collapsed' => TRUE,  // Added
        );
       
        $form[$group['machine_name'] . '_fieldset'][$group['machine_name'] . '_header'] = array(
	    '#type' => 'textarea',
	    '#title' => t('Header of ealert file'),
	    '#default_value' => variable_get($group['machine_name'] . '_header'),
	    '#description' => t("Enter header of ealert file."),
	    '#rows' => 25,
	    '#resizable' => TRUE,
	    '#required' => FALSE,
	);
	
        $form[$group['machine_name'] . '_fieldset'][$group['machine_name'] . '_footer'] = array(
	    '#type' => 'textarea',
	    '#title' => t('Footer of ealert file'),
	    '#default_value' => variable_get($group['machine_name'] . '_footer'),
            '#description' => t("Enter footer of ealert file"),
	    '#rows' => 25,
	    '#resizable' => TRUE,
	    '#required' => FALSE,
	);
    }

  $form['ealert_settings']['disclaimer_link'] = array(
    '#type' => 'textfield',
    '#title' => 'Disclaimer Link',
    '#default_value' => variable_get('disclaimer_link'),
    '#description' => 'The link to add body link for redirect.'
  );
  
  $form['ealert_settings']['disclaimer_pattern'] = array(
    '#type' => 'textfield',
    '#title' => 'Internal link pattern',
    '#default_value' => variable_get('disclaimer_pattern'),
    '#description' => 'Enter a regular expression for internal links.'
  );
  
  $form['ealert_settings']['add_disclaimer'] = array(
    '#type' => 'checkbox',
    '#title' => 'Add Disclaimer',
    '#default_value' => variable_get('add_disclaimer'),
    '#description' => 'Added disclaimer link.'
  );
  
  $form['ealert_settings']['sanitize'] = array(
    '#type' => 'checkbox',
    '#title' => 'Sanitize Text',
    '#default_value' => variable_get('sanitize'),
    '#description' => 'Sanitize the boby text.'
  );
    
  $form['ealert_settings']['ealert_member'] = array(
    '#type' => 'textfield',
    '#title' => 'Member name',
    '#default_value' => variable_get('ealert_member'),
    '#description' => 'The name of member, this helps to create google analytic code.'
  );
  $form['ealert_settings']['ealert_district'] = array(
    '#type' => 'textfield',
    '#title' => 'District',
    '#default_value' => variable_get('ealert_district'),
    '#description' => 'The name of member, this helps to create google analytic code.'
  );
  
  return system_settings_form($form);
}


