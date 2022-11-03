<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Lab8</title>

    <link rel="stylesheet" href="style.css">
  </head>
  <body>

    <h1>Lab8: SQL</h1>

    <div class="write-comment">
      <h2>Post a Comment</h2>

      <form action="http://localhost/Lab8/index.php" method="post">

        <label>
          Email Address:
          <input type="email" name="email">
        </label>

        <label>
          Mood:
          <select name="mood">
            <option value="happy">Happy</option>
            <option value="sad">Sad</option>
            <option value="excited">Excited</option>
            <option value="bored">Bored</option>
            <option value="angry">Angry</option>
          </select>
        </label>

        <label>
          Enter a Comment:
          <textarea name="comment"></textarea>
        </label>

        <button type="submit" name="button">Post Comment</button>

      </form>
    </div>
    <div>
    <?php
      the_comments();
      the_commenters();
     ?>
    </div>
  </body>
</html>
