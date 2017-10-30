<?php
	/**
		AQUI VAI POSSUIR O ARQUIVO DE TEXTO, PODE SER CHAMADO UM EXECUTAVEL COM ALGORITMO PARA COMPILAR OS ARQUIVOS
	**/
	#ini_set('default_charset','UTF-8');
	$myfile = fopen("newfile.txt", "w") or die("Unable to open file!");
	$txt = $_POST['teste'];
	fwrite($myfile, $txt);
	fclose($myfile);
?>
