<?php
/**
 * @file
 * hr_news.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_news_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_news';
  $feeds_importer->config = array(
    'name' => 'News',
    'description' => 'Import news from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title:en',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Title:fr',
            'target' => 'title_field:et:fr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Title:es',
            'target' => 'title_field:et:es',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Image',
            'target' => 'field_image',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Body:en',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Body:fr',
            'target' => 'body:et:fr',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Body:es',
            'target' => 'body:et:es',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Sectors',
            'target' => 'field_sectors:label',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Clusters/Sectors',
            'target' => 'field_bundles:label',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Organization',
            'target' => 'field_organizations:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Coordination hubs',
            'target' => 'field_coordination_hubs:label',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Locations',
            'target' => 'field_locations:label',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Fundings',
            'target' => 'field_funding_methods:label',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Themes',
            'target' => 'field_themes:label',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Disasters',
            'target' => 'field_disasters:label',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'Space',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'Post date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Author',
            'target' => 'user_mail',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'Language',
            'target' => 'language',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'panopoly_wysiwyg_text',
        'skip_hash_check' => 0,
        'bundle' => 'hr_news',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_news'] = $feeds_importer;

  return $export;
}
