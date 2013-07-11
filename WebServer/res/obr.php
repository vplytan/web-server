<?php

  $login = $_POST['login'];
  $pass = $_POST['pass'];
  if (($login == "Admin") && ($pass == "AdminPass"))
    header("Location: http://test1.ru/admin_pg.html");
  else echo "Доступ закритий";

?>