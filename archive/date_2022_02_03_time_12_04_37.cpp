// def query_game(N, A, Q, P):
// 	res = []
// 	for i in P:
// 		if i[0] == 1:
// 			A = reversed(A)

// 		if i[0] == 2:
// 			A[i[1] - 1], A[i[2] - 1] = A[i[2] - 1], A[i[1]- 1]

// 		if i[0] == 3:
// 			A = list(A)
// 			res.append(A.index(i[1]) + 1)

// 	return res



// def main():
// 	T = int(input())
// 	for _ in range(T):
// 		N = int(input())
// 		A = list(map(int, input().split()))
// 		Q = int(input())
// 		P = [list(map(int, input().split())) for i in range(Q)]
// 		out = query_game(N, A, Q, P)
// 		print(" ".join(map(str, out)))

// main()

#include <stdio.h>
#include <stdlib.h>

void query_game(int N, int *arr, int Q, int ** P){
	int tmp;
	for(int i = 0; i < Q; i++){
		if (P[i][0] == 1){
			reverse(arr);
		}

		else if(P[i][0] == 2){
			tmp = arr[P[i][1]];
			arr[P[i][1]] = arr[P[i][2]];
			arr[P[i][2]] = tmp;
		}

		else{
			
		}
	}
}


int main(){
	int T;
	scanf("%d", &T);
	for(int q = 0; q < T; q++){
		int N, Q;
		int *arr;

		scanf("%d", &N);
		arr = (int *) malloc (N * sizeof(int));

		for(int i = 0; i < N; i++){
			scanf("%d", &arr[i]);
		}

		scanf("%d", &Q);
		int (*p)[3] = (int (*)[3]) calloc(Q, 3 * sizeof (int));


		for(int i = 0; i < Q; i++){
			scanf("%d", &p[i][0]);
			scanf("%d", &p[i][1]);
			scanf("%d", &p[i][2]);
		}

		query_game(N, arr, Q, p)
	}
}


