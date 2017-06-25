<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8"/>
		<title>Compilador UFRN-ECT</title>
		
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
		
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
		<link rel="stylesheet" href="assets/style.css">
		
	</head>
	<body>
	
		<div class="container">
			<div class="row row-centered">
				<div class="col-md-3 col-centered">
					<img src="assets/img/ufrn_logo.png" class="img-responsive float-xs-left" alt="Logo UFRN" />
				</div>
				<div class="col-md-3 col-centered">
					<img src="assets/img/ect_logo.png" class="img-responsive float-xs-right" alt="Logo ECT"/>
				</div>
			</div>
			
			<div class="row row-centered">
				<div class="col-md-3 col-centered">
					<h2> Egepa </h2>
				</div>
			</div>
		</div>
		
		<div class="jumbotron">
			<div class="container">
				<p>
	Este questionário deve ser respondido por alunos que possuem conhecimento teórico e/ou prático da linguagem de programação C++.
	<br>
	Ele faz parte do projeto de pesquisa "Extensões de Gramáticas de Expressões de Parsing e suas Aplicações" desenvolvido por alunos da ECT.
	<br>
	<br>
	Pretende-se, por meio do questionário:
	<br>
	(i) identificar se diferentes mensagens de erros produzem diferentes respostas no tempo de correção dos algoritmos;
	<br>
	(ii) Identificar se a mesma mensagem de erro na lingua nativa tem melhor tempo de correção por parte dos alunos;
	<br>
	Termo de Compromisso:
	<br>
	-Garante-se ao participante que seus dados pessoais serão mantidos em completo sigilo.
	<br>
	-Destaca-se que, ao responder este questionário, você autoriza o uso das respostas fornecidas na pesquisa relacionada.
	<br><br>
	Desde já, agradecemos a sua participação.
				</p>
				
				<div class="row" style="height:10%">
					<div class="col-md-5 col-md-offset-5">
						<button type="button" class="btn btn-primary btn-lg" id="aceito">Aceito</button>
						<button type="button" class="btn btn-primary btn-lg" id="naoAceito">Não aceito</button>
					</div>
				</div>
			</div>
		</div>
	</body>
	
	<script>
	$(function() {
			$('#aceito').click(function(){
				window.location = "login.php";
			});
			$('#naoAceito').click(function(){
				alert("Ok, obrigado pela sua participação");
				window.location = "http://www.google.com.br";
			});
	});
	</script>
</html>