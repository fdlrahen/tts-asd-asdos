#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NODES 100
#define MAX_EDGES 1000

struct Edge {
    int from;   // yang merupakan node asal (source node) pada sisi tersebut.
    int to;     // yang merupakan node tujuan (destination node) pada sisi tersebut.
    int weight; //  yang merupakan bobot (weight) pada sisi tersebut.
};

struct Graph {
    int num_nodes;      // yang merupakan jumlah node (simpul) dalam graph tersebut.
    int num_edges;      // yang merupakan jumlah sisi (edge) dalam graph tersebut.
    struct Edge edges[MAX_EDGES]; // yang merupakan array dari struktur Edge (sisi) yang merepresentasikan semua sisi pada graph tersebut.
};

void add_edge(struct Graph* graph, int from, int to, int weight) {
    graph->edges[graph->num_edges++] = (struct Edge) { from, to, weight };
}

    /*
    merupakan implementasi dari sebuah fungsi "add_edge" digunakan untuk menambahkan sebuah edge (sisi) baru pada sebuah graph (graf).
    Fungsi "add_edge" tersebut menerima 4 parameter yaitu:

    Pointer ke struktur Graph yang merepresentasikan graph yang ingin ditambahkan edge-nya.
    Fungsi "add_edge" ini mengakses variabel "edges" pada struktur Graph yang merupakan array dari Edge (sisi)
    yang telah didefinisikan sebelumnya. Kemudian, fungsi ini menambahkan sisi baru dengan memasukkan nilai
    "from", "to", dan "weight" ke dalam elemen array "edges" pada index yang ditunjukkan oleh "num_edges", yang
    nantinya "num_edges" akan di-increment untuk menunjukkan bahwa sudah ada satu sisi baru yang ditambahkan ke dalam graph.

    Dengan demikian, ketika fungsi "add_edge" dipanggil, maka sisi baru tersebut akan ditambahkan ke dalam graph yang telah
    didefinisikan sebelumnya.
    */

void find_shortest_path(struct Graph* graph, int start, int end) {
    int distances[MAX_NODES], previous[MAX_NODES], visited[MAX_NODES], i, j, min_distance, next_node;
    // "find_shortest_path" pada program C untuk mencari jalur terpendek (shortest path)
    // antara dua node pada graph yang telah didefinisikan sebelumnya.


    // menginisialisasi arrays distances, previous, dan visited
    for (i = 0; i < graph->num_nodes; i++)
        distances[i] = INT_MAX, previous[i] = -1, visited[i] = 0;
    /*
    memastikan bahwa setiap node belum dikunjungi dan jarak awal ke setiap node adalah tak terbatas.
    Dengan inisialisasi yang benar, algoritma Dijkstra akan berfungsi dengan benar
    untuk menghitung jarak terpendek antara node awal dan node tujuan pada graph yang diberikan.
    */

    // set jarak dari node awal ke nol
    distances[start] = 0;

    // melakukan iterasi pada semua node
    for (i = 0; i < graph->num_nodes; i++) {
        min_distance = INT_MAX;
        for (j = 0; j < graph->num_nodes; j++)
            if (!visited[j] && distances[j] <= min_distance)
                min_distance = distances[next_node = j];
    /*
    dilakukan perulangan untuk mencari node dengan jarak terpendek dari node awal.
    Pertama, variabel min_distance diinisialisasi dengan nilai INT_MAX untuk memastikan bahwa
    nilai jarak terkecil dari node awal ke node tujuan akan ditemukan pada iterasi pertama.
    */

        // menandai node saat ini sebagai sudah dikunjungi
        visited[next_node] = 1;

        // memperbarui jarak dan node sebelumnya untuk semua tetangga node saat ini
        for (j = 0; j < graph->num_edges; j++)
            if (graph->edges[j].from == next_node) {
                int neighbor = graph->edges[j].to;
                int distance = graph->edges[j].weight;
                int total_distance = distances[next_node] + distance;
                if (total_distance < distances[neighbor])
                    distances[neighbor] = total_distance, previous[neighbor] = next_node;
            }
    }
    /*
    ilakukan perulangan untuk memeriksa setiap edge pada graph untuk menemukan tetangga-tetangga
    dari node dengan jarak terpendek dari node awal (yang telah ditemukan pada potongan kode sebelumnya).
    */

    // mencetak jalur terpendek
    printf(" Jalur terpendek dari %d ke %d:\n%d", start, end, end);
    for (int current_node = end; current_node != start; current_node = previous[current_node])
        printf(" <- %d", previous[current_node]);
    printf("\n");
}
    /*
    Setelah algoritma Dijkstra selesai dijalankan dan jarak terpendek dari node awal (start)
    ke node tujuan (end) telah ditemukan, potongan kode tersebut akan mencetak jalur terpendek tersebut
    menggunakan perulangan "for". Perulangan dimulai dari node tujuan (end) dan akan berlangsung hingga
    mencapai node awal (start) dengan mengikuti informasi node sebelumnya yang disimpan dalam array previous.
    */


int main() {
    struct Graph graph = { 5, 0 };
    add_edge(&graph, 0, 1, 10);
    add_edge(&graph, 0, 3, 5);
    add_edge(&graph, 1, 2, 1);
    add_edge(&graph, 1, 3, 2);
    add_edge(&graph, 2, 4, 4);
    add_edge(&graph, 3, 1, 3);
    add_edge(&graph, 3, 2, 9);
    add_edge(&graph, 3, 4, 2);
    add_edge(&graph, 4, 0, 7);
    add_edge(&graph, 4, 2, 6);

    /*
    kita memanggil fungsi "add_edge" sebanyak 10 kali dengan argumen graph dan beberapa nilai parameter
    seperti node asal, node tujuan, dan bobot dari sisi (edge) tersebut.
    Fungsi "add_edge" akan menambahkan sisi-sisi tersebut ke dalam graph yang telah didefinisikan sebelumnya.
    */
    printf("Daftar rute pengiriman barang:\n");

    // Menentukan rute pengiriman barang dengan mencari jalur terpendek antara titik awal dan akhir

    find_shortest_path(&graph, 0, 2);
    find_shortest_path(&graph, 1, 4);
    find_shortest_path(&graph, 0, 4);
    find_shortest_path(&graph, 3, 0);
    find_shortest_path(&graph, 4, 3);

    /*
    "find_shortest_path" untuk mencari jalur terpendek (shortest path) antara dua node pada graph yang telah dibuat sebelumnya.
    algoritma Dijkstra untuk mencari jalur terpendek pada sebuah graph
    */
return 0;

}
