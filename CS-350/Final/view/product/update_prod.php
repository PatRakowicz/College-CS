<?php function render_update_prod($product) { ?>
	<h1>Update Record</h1>
	<form action="./index.php?action=update_prod" method="post">
		<input type="hidden" name="product_id" value="<?= $product['id'] ?>">
		<div>
			<label for="name">Name:</label>
			<input type="text" id="name" name="name" value="<?= $product['name'] ?>" required>
		</div>
		<div>
			<label for="description">Description:</label>
			<textarea id="description" name="description" required><?= $product['description'] ?></textarea>
		</div>
		<div>
			<label for="price">Price:</label>
			<input type="text" id="price" name="price" value="<?= $product['price'] ?>" required pattern="\d+(\.\d{1,2})?">
		</div>
		<input type="submit">
	</form>
<?php } ?>