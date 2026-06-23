#include <stdio.h>

int quantidadeDeAlunos;
char nomesDosAlunos[40][100];
float notasDosAlunos[40][5];
float mediasDosAlunos[40];
int quantidadeDeAvaliacoes;

float calcularMedia(float notas[], int qtd) {
    float soma = 0;
    int i;
    for (i = 0; i < qtd; i++) {
        soma = soma + notas[i];
    }
    return soma / qtd;
}

void cadastrarNomes() {
    int i;
    for (i = 0; i < quantidadeDeAlunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", nomesDosAlunos[i]);
    }
    printf("Nomes cadastrados com sucesso!\n");
}

void cadastrarNotas() {
    int i, j;
    for (i = 0; i < quantidadeDeAlunos; i++) {
        printf("\nAluno: %s\n", nomesDosAlunos[i]);
        for (j = 0; j < quantidadeDeAvaliacoes; j++) {
            printf("Digite a nota da avaliacao %d: ", j + 1);
            scanf("%f", &notasDosAlunos[i][j]);
            while (notasDosAlunos[i][j] < 0 || notasDosAlunos[i][j] > 10) {
                printf("Nota invalida! Digite um valor entre 0 e 10: ");
                scanf("%f", &notasDosAlunos[i][j]);
            }
        }
    }
    printf("Notas cadastradas com sucesso!\n");
}

void mostrarDados() {
    int i, j;
    printf("\n========== DADOS CADASTRADOS ==========\n");
    for (i = 0; i < quantidadeDeAlunos; i++) {
        printf("Aluno %d: %s\n", i + 1, nomesDosAlunos[i]);
        for (j = 0; j < quantidadeDeAvaliacoes; j++) {
            printf("  Nota %d: %.2f\n", j + 1, notasDosAlunos[i][j]);
        }
        printf("\n");
    }
}

void calcularTodasMedias() {
    int i;
    for (i = 0; i < quantidadeDeAlunos; i++) {
        mediasDosAlunos[i] = calcularMedia(notasDosAlunos[i], quantidadeDeAvaliacoes);
        printf("Media do aluno %s: %.2f\n", nomesDosAlunos[i], mediasDosAlunos[i]);
    }
}

void mostrarBoletim() {
    int i;
    printf("\n========== BOLETIM ==========\n");
    for (i = 0; i < quantidadeDeAlunos; i++) {
        printf("Aluno: %s\n", nomesDosAlunos[i]);
        printf("Media: %.2f\n", mediasDosAlunos[i]);
        if (mediasDosAlunos[i] >= 7) {
            printf("Situacao: Aprovado\n");
        }
        else if (mediasDosAlunos[i] >= 4) {
            printf("Situacao: Recuperacao\n");
        }
        else {
            printf("Situacao: Reprovado\n");
        }
        printf("\n");
    }
}

void mostrarEstatisticas() {
    int i;
    float somaMedias = 0;
    float maiorMedia = mediasDosAlunos[0];
    float menorMedia = mediasDosAlunos[0];
    int indiceMaior = 0;
    int indiceMenor = 0;
    int aprovados = 0;

    for (i = 0; i < quantidadeDeAlunos; i++) {
        somaMedias = somaMedias + mediasDosAlunos[i];
        if (mediasDosAlunos[i] > maiorMedia) {
            maiorMedia = mediasDosAlunos[i];
            indiceMaior = i;
        }
        if (mediasDosAlunos[i] < menorMedia) {
            menorMedia = mediasDosAlunos[i];
            indiceMenor = i;
        }
        if (mediasDosAlunos[i] >= 7) {
            aprovados++;
        }
    }

    printf("\n========== ESTATISTICAS ==========\n");
    printf("Media geral da turma: %.2f\n", somaMedias / quantidadeDeAlunos);
    printf("Maior media: %.2f (Aluno: %s)\n", maiorMedia, nomesDosAlunos[indiceMaior]);
    printf("Menor media: %.2f (Aluno: %s)\n", menorMedia, nomesDosAlunos[indiceMenor]);
    printf("Percentual de aprovados: %.2f%%\n", (float)aprovados / quantidadeDeAlunos * 100);
}

int main() {
    int opcao;

    printf("=== SISTEMA DE NOTAS ===\n");
    printf("Quantos alunos tem na turma? ");
    scanf("%d", &quantidadeDeAlunos);
    printf("Quantas avaliacoes teve a disciplina? ");
    scanf("%d", &quantidadeDeAvaliacoes);

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Cadastrar nomes dos alunos\n");
        printf("2 - Cadastrar notas dos alunos\n");
        printf("3 - Mostrar todos os dados\n");
        printf("4 - Calcular medias\n");
        printf("5 - Mostrar boletim\n");
        printf("6 - Estatisticas da turma\n");
        printf("7 - Sair do programa\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarNomes();
                break;
            case 2:
                cadastrarNotas();
                break;
            case 3:
                mostrarDados();
                break;
            case 4:
                calcularTodasMedias();
                break;
            case 5:
                mostrarBoletim();
                break;
            case 6:
                mostrarEstatisticas();
                break;
            case 7:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
