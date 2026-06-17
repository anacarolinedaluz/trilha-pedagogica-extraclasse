#include <stdio.h>

int quantidadeDeAlunos;
char nomesDosAlunos[40][100];
float notasDosAlunos[40][5];
float mediasDosAlunos[40];
int quantidadeDeAvaliacoes;

int main() {
    int opcao;
    int i, j;

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
        printf("5 - Sair do programa\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            for (i = 0; i < quantidadeDeAlunos; i++) {
                printf("Digite o nome do aluno %d: ", i + 1);
                scanf("%s", nomesDosAlunos[i]);
            }
            printf("Nomes cadastrados com sucesso!\n");
        }
        else if (opcao == 2) {
            for (i = 0; i < quantidadeDeAlunos; i++) {
                printf("\nAluno: %s\n", nomesDosAlunos[i]);
                for (j = 0; j < quantidadeDeAvaliacoes; j++) {
                    printf("Digite a nota da avaliacao %d: ", j + 1);
                    scanf("%f", &notasDosAlunos[i][j]);
                }
            }
            printf("Notas cadastradas com sucesso!\n");
        }
        else if (opcao == 3) {
            printf("\n========== DADOS CADASTRADOS ==========\n");
            for (i = 0; i < quantidadeDeAlunos; i++) {
                printf("Aluno %d: %s\n", i + 1, nomesDosAlunos[i]);
                for (j = 0; j < quantidadeDeAvaliacoes; j++) {
                    printf("  Nota %d: %.2f\n", j + 1, notasDosAlunos[i][j]);
                }
                printf("\n");
            }
        }
        else if (opcao == 4) {
            for (i = 0; i < quantidadeDeAlunos; i++) {
                float soma = 0;
                for (j = 0; j < quantidadeDeAvaliacoes; j++) {
                    soma = soma + notasDosAlunos[i][j];
                }
                mediasDosAlunos[i] = soma / quantidadeDeAvaliacoes;
                printf("Media do aluno %s: %.2f\n", nomesDosAlunos[i], mediasDosAlunos[i]);
            }
        }
        else if (opcao == 5) {
            printf("Saindo do programa...\n");
        }
        else {
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
