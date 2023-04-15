<?php
require_once 'model.php';
require_once 'view/create_user.php';
require_once 'view/home.php';
require_once 'view/login.php';
require_once 'view/secret.php';
require_once 'view/logout.php';

function display_home($users)
{
    render_header();
    render_home($users);
    render_footer();
}

function display_create_user($error = null)
{
    render_header();
    render_create_user($error);
    render_footer();
}

function display_login($error = null)
{
    render_header();
    render_login($error);
    render_footer();
}

function display_secret($user)
{
    render_header();
    render_secret($user);
    render_footer();
}

function display_logout()
{
    render_header();
    render_logout();
    render_footer();
}

function render_header()
{
    require_once 'view/header.php';
}

function render_footer()
{
    require_once 'view/footer.php';
}
