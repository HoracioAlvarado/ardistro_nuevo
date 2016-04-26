<?php
/**
* @file
* Template for the 1 column panel layout.
*
* This template provides a three column 25%-50%-25% panel display layout.
*
* Variables:
* - $id: An optional CSS id to use for the layout.
* - $content: An array of content, each item in the array is keyed to one
*   panel of the layout. This layout supports the following sections:
*   - $content['left']: Content in the left column.
*   - $content['middle']: Content in the middle column.
*   - $content['right']: Content in the right column.
*/
?>
<div class="clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; }?>>
	<!-- Imagen destacada -->
	<div class="u-tpl-col-12 panel-panel panel-col-first">
		<div class="inside"><?php print $content['destacado']; ?></div>
	</div>
	<!-- /Imagen destacada -->
	<!-- Atajos -->
	<div class="u-tpl-col-12 panel-panel">
		<div class="inside"><?php print $content['atajos']; ?></div>
	</div>
	<!-- /Atajos -->
	<!-- Novedades -->
	<div class="u-tpl-col-12 panel-panel bg-grey">
		<div class="inside"><?php print $content['novedades']; ?></div>
	</div>
	<!-- /Novedades -->

	<!-- Banners -->
	<div class="u-tpl-col-12 panel-panel bg-grey">
		<div class="row">
			<div class="inside"><?php print $content['enlaces']; ?></div>
		</div>
	</div>
	<!-- /Banners -->


</div>