<section class="imagen-destacada clearfix">
	<?php if(!empty($link)): ?>
	<a href="<?php print $link ?>"
		target="<?php print $tipo_de_link ?>">
		<?php endif; ?>
		<div class="col-md-8 nopadding">
			<div class="img-container">
				<?php print $imagen ?>
			</div>
		</div>
		<div class="col-md-4 nopadding">
			<div class="descripcion">
				<h1><?php print $titulo; ?></h1>
				<p><?php print $bajada; ?></p>
			</div>
		</div>
	<?php if(!empty($link)): ?></a><?php endif; ?>
</section>