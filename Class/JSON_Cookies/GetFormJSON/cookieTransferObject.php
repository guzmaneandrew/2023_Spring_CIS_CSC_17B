<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>3 Read Cookie from JavaScript and Translate to PHP</title>
    </head>
    <body>
        <h1>3 Read Cookie from JavaScript and Translate to PHP</h1>
        <?php
            echo "Gotta Read the cookie </br>";
            $text=$_COOKIE["object"];
            echo $text."</br>";
            $myObj = json_decode($text);
            echo '<pre>';
            var_dump($myObj);
            echo '</pre>';
        ?>
    </body>
</html>
