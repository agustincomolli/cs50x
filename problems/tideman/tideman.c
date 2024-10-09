#include <cs50.h>
#include <stdio.h>
#include <string.h> // Para uso de strcmp().

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cycle_exists(int candidate_1, int cadidate_2);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        // Si es un candidato válido.
        if (strcmp(candidates[i], name) == 0)
        {
            // Guardar el índice del candidato en la lista del votante.
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int candidate_1;
    int candidate_2;

    for (int i = 0; i < candidate_count - 1; i++)
    {
        candidate_1 = ranks[i];
        for (int j = i + 1; j < candidate_count; j++)
        {
            candidate_2 = ranks[j];
            preferences[candidate_1][candidate_2]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // Empiezo con el primer para '0' y a medida que agrego pares aumento
    // pair_count en 1.
    pair_count = 0;
    // Recorro los canidatos del 1º al anteúltimo.
    for (int i = 0; i < candidate_count - 1; i++)
    {
        // Recorro los candidatos desde el siguiente hasta el último.
        // Esto hace que la matriz preferences[0][0], [1][1],...[n][n] no se consideren.
        for (int j = i + 1; j < candidate_count; j++)
        {
            // En el par de candidatos se revisan los votos y se agrega a pairs[]
            // si hay un ganador.
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
// La "fuerza de la victoria" se define como la diferencia entre el número
// de votantes que prefieren al candidato ganador sobre el perdedor.
void sort_pairs(void)
{
    // TODO
    // Ordenar por el método de la burbuja.
    pair smaller;
    bool swapped;

    for (int i = 0; i < pair_count - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < pair_count - i - 1; j++)
        {
            // Calcular la diferencia de votos entre el candidato ganador y el perdedor.
            int difference_1 = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            // Calcular la diferencia de votos del siguiente candidato.
            int difference_2 =
                preferences[pairs[j + 1].winner][pairs[j + 1].loser] - preferences[pairs[j + 1].loser][pairs[j + 1].winner];

            // Si difference_1 es menor que difference_2, significa que el
            // par en la posición j tiene una "fuerza de victoria" menor que el
            // par en la posición j + 1, por lo que se intercambian para
            // que el par con la mayor "fuerza de victoria" aparezca primero.
            if (difference_1 < difference_2)
            {
                smaller = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = smaller;

                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int candidate_1;
    int candidate_2;
    for (int i = 0; i < pair_count; i++)
    {
        candidate_1 = pairs[i].winner;
        candidate_2 = pairs[i].loser;
        if (!cycle_exists(candidate_1, candidate_2))
        {
            locked[candidate_1][candidate_2] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    // Para saber quien es el ganador, un columna de la tabla locked
    // no deberá tener ningún true y ese número de columna será el candidato
    // que gane.
    for (int i = 0; i < candidate_count; i++)
    {
        bool has_arrow = false;
        for (int j = 0; j < candidate_count; j ++)
        {
            if (locked[j][i])
            {
                has_arrow = true;
            }
        }
        if (!has_arrow)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}

bool cycle_exists(int winner, int loser)
{
    // Caso base
    if (winner == loser)
    {
        return true;
    }

    // Recorrer los pares de candidatos.
    for (int i = 0; i < pair_count; i++)
    {
        // Si el par perdedor e i están en la matriz de bloqueo y
        // se genera un ciclo...
        if (locked[loser][i] && cycle_exists(winner, i))
        {
            return true;
        }
    }
    return false;
}
