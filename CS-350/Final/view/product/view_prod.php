<?php function render_view_prod($products, $error = null) { ?>
	<h1>View your Products</h1>
	<?php if ($error): ?>
		<p class="error"><?= $error ?></p>
	<?php endif; ?>
	<table>
		<thead>
		<tr>
			<th>Name</th>
			<th>Description</th>
			<th>Price</th>
		</tr>
		</thead>
		<tbody>
		<?php foreach ($products as $product): ?>
			<tr>
				<td><?= $product['name'] ?></td>
				<td><?= $product['description'] ?></td>
				<td><?= $product['price'] ?></td>
				<td>
					<a href="./index.php?action=update_prod&id=<?= $product['id'] ?>">Update</a>
					<a href="./index.php?action=delete_prod&id=<?= $product['id'] ?>">Delete</a>
				</td>
			</tr>
		<?php endforeach; ?>
		</tbody>
	</table>
<?php } ?>