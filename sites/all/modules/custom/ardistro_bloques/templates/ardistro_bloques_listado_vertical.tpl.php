<h3 class="h4"><?php echo $titulo; ?></h3>
<ul class="list-group">
  <?php foreach ($links as $link) { ?>
    <li class="list-group-item">
      <?php echo $link; ?>
    </li>
  <?php } ?>
</ul>
<?php if(isset($boton)) { print $boton; }
