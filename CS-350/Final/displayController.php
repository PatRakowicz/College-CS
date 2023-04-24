<?php
require_once 'model.php';
require_once 'view/create_user.php';
require_once 'view/home.php';
require_once 'view/login.php';
require_once 'view/logout.php';
require_once 'view/product/create_prod.php';
require_once 'view/product/view_prod.php';
require_once 'view/product/update_prod.php';

function display_home($user = null) {
	render_header();
	render_home($user);
	render_footer();
}

function display_create_user($error = null) {
	render_header();
	render_create_user($error);
	render_footer();
}

function display_login($error = null) {
	render_header();
	render_login($error);
	render_footer();
}


function display_logout() {
	render_header();
	render_logout();
	render_footer();
}

function display_create_prod() {
	render_header();
	render_create_prod();
	render_footer();
}

function display_view_prod($products, $error = null) {
	render_header();
	render_view_prod($products, $error);
	render_footer();
}

function display_update_prod($product_id) {
	$model = new Model();
	$product = $model->getProductById($product_id);
	if ($product) {
		render_header();
		render_update_prod($product);
		render_footer();
	} else {
		display_view_prod($model->getProductsByUserId($_SESSION['user_id']), "Product not found.");
	}
}

function render_header() {
	require_once 'view/header.php';
}

function render_footer() {
	require_once 'view/footer.php';
}
