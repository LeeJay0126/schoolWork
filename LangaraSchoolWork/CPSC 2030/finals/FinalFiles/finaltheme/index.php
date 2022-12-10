<?php
get_header();

if(have_posts())
{
  while(have_posts())
  {
    the_post();
	
	 ?>

    <li><button id='<?php echo get_the_ID(); ?>'><?php the_title(); ?></button></li>
	
	<!-- insert your code below -->
	
	
	<?php
  }
}
get_footer();
?>
