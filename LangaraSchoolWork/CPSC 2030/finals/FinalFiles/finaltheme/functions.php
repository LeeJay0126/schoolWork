<?php  

function final_styles_and_scripts()
{
  wp_enqueue_script('nav', get_template_directory_uri() . '/scripts/nav.js', array(), time());

  wp_enqueue_style('style', get_template_directory_uri() . '/style.css', array(), time());

}
add_action('wp_enqueue_scripts', 'final_styles_and_scripts')

?>
