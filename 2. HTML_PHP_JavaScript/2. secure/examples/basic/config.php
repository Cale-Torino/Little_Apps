<?php
/**
 * For Development Purposes
 */
ini_set('display_errors', 'on');

require __DIR__ . '/../../vendor/autoload.php';

$LS = new \Fr\LS(array(
    'db'       => array(
        'host'     => 'localhost',
        'port'     => 3306,
        'username' => 'root',
        'password' => '',
        'name'     => 'securephplogin',
        'table'    => 'users',
    ),
    'features' => array(
        'auto_init' => true,
        'two_step_login' => true,
    ),
    'pages'    => array(
        'no_login'   => array(
            '/',
            '/secure/examples/basic/reset.php',
            '/secure/examples/basic/register.php',
        ),
        'everyone'   => array(
            '/secure/examples/basic/status.php',
        ),
        'login_page' => '/secure/examples/basic/login.php',
        'home_page'  => '/secure/examples/basic/home.php',
    ),
));