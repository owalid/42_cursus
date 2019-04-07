<?php
include('../php/query.php');
session_start();
function get_categorie(){
	$categories = get_all_categories();
	foreach ($categories as $cat)
	{
		echo '<a href="../php/produits.php?categorie=' . $cat['id_cat'] . '"><li>' . $cat['name_cat'] . '</li></a>';
	}
}
if ($_SESSION['loggued_on_user'] != '')
	$user = $_SESSION['loggued_on_user'];
else
	echo '';
?>
<html>
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="../css/choice.css">
		<title>index</title>
	</head>
	<body>
	<nav role="navigation">
		<div id="menuToggle">
			<input type="checkbox" />
			<span></span>
			<span></span>
			<span></span>
			<ul id="menu">
				<p class="bonjour">Bonjour <?php echo $user; ?></p>
				<?php get_categorie(); ?>
				<a href="../php/panier.php"><li>Panier</li></a>
				<a href="../php/checksettings.php"><li>Setting</li></a>
				<a href="../php/logout.php"><li>Logout</li></a>
			</ul>
		</div>
	</nav>
	<p><a id="name-site" href="../php/checklogin.php">ChaudSet</a></p>
	<?php $categories = get_all_categories();
	foreach ($categories as $cat)
	{
		echo '<a id="cate" href="../php/produits.php?categorie=' . $cat['id_cat'] . '">' . $cat['name_cat'] . '</a><br /><br />';
	} ?>
	</body>
</html>
