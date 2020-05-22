#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Procesor {
   public:
    int indice;
    int ocupat;

    Procesor() {}
    Procesor(int indice, int ocupat) {
        this->indice = indice;
        this->ocupat = ocupat;
    }
};

vector<Procesor> heapOcupate;
vector<Procesor> heapDisponibile;

void add_in_ocupate(Procesor p) {
    heapOcupate.push_back(p);

    int poz = heapOcupate.size() - 1;

    while (poz / 2 > 0 && heapOcupate[poz / 2].ocupat > heapOcupate[poz].ocupat) {
        swap(heapOcupate[poz / 2], heapOcupate[poz]);

        poz /= 2;
    }
}

Procesor extract_from_ocupate() {
    Procesor to_return = heapOcupate[1];

    int naux = heapOcupate.size() - 1;
    swap(heapOcupate[1], heapOcupate[naux]);

    heapOcupate.pop_back();
    naux -= 1;

    int poz = 1;
    bool t = false;

    while (!t) {
        if ((poz * 2 > naux && poz * 2 + 1 > naux) || (heapOcupate[poz * 2].ocupat >= heapOcupate[poz].ocupat && heapOcupate[poz * 2 + 1].ocupat >= heapOcupate[poz].ocupat)) {
            t = true;
        } else if (poz * 2 <= naux && poz * 2 + 1 <= naux) {
            if (heapOcupate[poz * 2].ocupat < heapOcupate[poz * 2 + 1].ocupat) {
                swap(heapOcupate[poz], heapOcupate[poz * 2]);
                poz = poz * 2;
            } else {
                swap(heapOcupate[poz], heapOcupate[poz * 2 + 1]);
                poz = poz * 2 + 1;
            }
        } else if (poz * 2 <= naux && heapOcupate[poz * 2].ocupat < heapOcupate[poz].ocupat) {
            swap(heapOcupate[poz], heapOcupate[poz * 2]);
            poz = poz * 2;
        } else if (poz * 2 > naux && heapOcupate[poz * 2 + 1].ocupat < heapOcupate[poz].ocupat) {
            swap(heapOcupate[poz], heapOcupate[poz * 2 + 1]);
            poz = poz * 2 + 1;
        } else {
            t = true;
        }
    }
    return to_return;
}

Procesor extract_from_disponibile() {
    Procesor to_return = heapDisponibile[1];

    int naux = heapDisponibile.size() - 1;
    swap(heapDisponibile[1], heapDisponibile[naux]);

    heapDisponibile.pop_back();
    naux -= 1;

    int poz = 1;
    bool t = false;

    while (!t) {
        if ((poz * 2 > naux && poz * 2 + 1 > naux) || (heapDisponibile[poz * 2].indice >= heapDisponibile[poz].indice && heapDisponibile[poz * 2 + 1].indice >= heapDisponibile[poz].indice)) {
            t = true;
        } else if (poz * 2 <= naux && poz * 2 + 1 <= naux) {
            if (heapDisponibile[poz * 2].indice < heapDisponibile[poz * 2 + 1].indice) {
                swap(heapDisponibile[poz], heapDisponibile[poz * 2]);
                poz = poz * 2;
            } else {
                swap(heapDisponibile[poz], heapDisponibile[poz * 2 + 1]);
                poz = poz * 2 + 1;
            }
        } else if (poz * 2 <= naux && heapDisponibile[poz * 2].indice < heapDisponibile[poz].indice) {
            swap(heapDisponibile[poz], heapDisponibile[poz * 2]);
            poz = poz * 2;
        } else if (poz * 2 > naux && heapDisponibile[poz * 2 + 1].indice < heapDisponibile[poz].indice) {
            swap(heapDisponibile[poz], heapDisponibile[poz * 2 + 1]);
            poz = poz * 2 + 1;
        } else {
            t = true;
        }
    }
    return to_return;
}

int main() {
    ifstream fin("proc2.in", ios::in);
    ofstream fout("proc2.out", ios::out);

    Procesor buffer(-1, -1);
    heapDisponibile.push_back(buffer);
    heapOcupate.push_back(buffer);

    int n, m;
    fin >> n >> m;
    n = m;

    for (int proc = 0; proc < n; proc++) {
        Procesor aux(proc, 0);

        heapDisponibile.push_back(aux);
        int poz = heapDisponibile.size() - 1;
        while (poz / 2 > 0 && heapDisponibile[poz / 2].indice > heapDisponibile[poz].indice) {
            swap(heapDisponibile[poz / 2], heapDisponibile[poz]);
            poz /= 2;
        }
    }
    int si, di;
    Procesor to_transfer;

    for (int i = 0; i < m; i++) {
        fin >> si >> di;

        while (heapOcupate.size() > 1 && heapOcupate[1].ocupat <= si) {
            to_transfer = extract_from_ocupate();

            heapDisponibile.push_back(to_transfer);

            int poz = heapDisponibile.size() - 1;

            while (poz / 2 > 0 && heapDisponibile[poz / 2].indice > heapDisponibile[poz].indice) {
                swap(heapDisponibile[poz / 2], heapDisponibile[poz]);
                poz /= 2;
            }
        }

        to_transfer = extract_from_disponibile();
        to_transfer.ocupat = si + di;
        add_in_ocupate(to_transfer);
        fout << to_transfer.indice + 1 << '\n';
    }
    return 0;
}