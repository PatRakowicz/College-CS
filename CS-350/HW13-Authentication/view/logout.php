<?php
require((realpath(dirname(__FILE__) . '/..') . '/header.php'));
session_start();
session_unset();
session_destroy();
header('Location: index.php?action=login');
exit();