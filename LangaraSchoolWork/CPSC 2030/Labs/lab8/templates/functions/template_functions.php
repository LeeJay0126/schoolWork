<?php
// Output comments to HTM

function the_comments() {
  global $posts;

  // foreach($posts as $post){
  //   foreach($post as $postElement){
  //     echo $postElement;
  //   }
  // }

  echo "<h2>Comment</h2>";

  foreach($posts as $post){

    echo "
    <div class='comment'> 
    <p class='ID'> Post ID : ". $post[0] . "</p>" . "<p class='date'> Posted on : ".$post[4]."</p>".
    "<h3>New Comment By:" . $post[1]. " </h3>
    <p>Current mood: ".$post[3]."</p>". 
    "<p class='comment-text'> Current mood: ".$post[2]. "</p>"
    ."</div>";
  }
  // TODO

}

// Output unique email addresses to HTML
function the_commenters() {

  echo "<h2>People Who Have Commented: </h2>";

  global $commenters;

  foreach($commenters as $commenter){
    echo "<li>".$commenter."</li>";
  }

  // echo $commenters;
  //TODO

}
