<?php
$myName = "Jay Lee";
$description = "My name is Jay Lee and I'm 24 years old. I love MMA and I train jiujitsu";
$favorite_animals = ["cow", "pig", "chicken", "goat", "dog", "cat", "lion"];

function the_developer_profile()
{
  global $myName, $description, $favorite_animals;
  echo
    '<div>
      <h2>Developer Profile ' . $myName . '</h2>
    </div>';
  echo 
    '<div>
      Desciption: ' .$description. '
    </div>' ;
  $string = "My favorite animals are ";
  for($i = 0; $i < count($favorite_animals); $i+=1){
    if($i == count($favorite_animals)-1){
      $string .= "and " . $favorite_animals[$i] . ".";
    }else{
      $string .= $favorite_animals[$i] .  " ";
    }
  };
  echo 
    '<div>
      <p>'.$string.'</p>
    </div>';
};

function the_color_form(){
  echo '
  <div>
    <form action="lab6.php" method="post">
      <p>Which color do you prefer for the text of this page?</p>
      <input type="color" name="color"/>
      <input type="submit" value="Submit"></input>
    </form>
  </div>
  ';
};

function get_color(){
  if(isset($_POST["color"])){
    return $_POST["color"];
  }else{
    return "#000";
  }
};

?>
<!DOCTYPE html>
<html style="color: <?php echo get_color(); ?> ;">

<head>
  <meta charset="utf-8">
  <title>Lab6: Hello PHP World!</title>

</head>

<body>

  <header>
    <h1>Hello PHP World!</h1>
    <div>
      An Introduction to Server-Side Scripting.
    </div>
  </header>

  <main>
    <?php
    the_developer_profile();
    the_color_form();
    ?>
  </main>

</body>

</html>
