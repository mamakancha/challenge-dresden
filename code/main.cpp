#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void add_edge(Graph & graph, int u, int v, bool type) 
{
	graph[u][v] += (2 * type - 1);
	graph[v][u] += (2 * type - 1);
	graph[u][v] = max(graph[u][v], 0);
	graph[v][u] = max(graph[v][u], 0);
}



/* Standard Depth First Search (dfs) implementation */
void dfs(Graph & g, int u, vector<bool> & visited) 
{
	visited[u] = true;
	for(int v = 0; v < (int)g.size(); v ++) 
	{
		if(!visited[v] && g[u][v])
			dfs(g, v, visited);
	}
}

int find_components(Graph & g) 
{
	int n = (int)g.size();
	vector<bool> visited(n, 0); /* All nodes are unvisited initially */
	int ans = 0;
	for(int i = 0; i < n; i ++) 
		if(!visited[i]) /* Applying dfs on individual nodes. */
		{
			ans++;
			dfs(g, i, visited); 
			/* The number of times dfs 
			is called is the number
			of connected components */
		}
	return ans;
}

void update_components(int & previous, Graph & g) 
{
	int new_components = find_components(g);
	if(previous != new_components) /* If number of components change we print new value*/
	{
		cout << "The graph has " << new_components << " connected components." << endl;
	}
	previous = new_components; /* Update components */
}



int get_nodes() /* Get the number of nodes from console */
{  
	int n;
	while(true) 
	{
		cin >> n;
		if(n >= 0 && n <= 64) return n;
		cout << "Invalid Input. Nodes should be >= 0 and <= 64" << endl;
	}
}



int32_t main()   /* main function starts here */

{   
	
	cout << "Enter the number of nodes (<=64):" << endl;
	int nodes = get_nodes();
	int components = 0;

	/*This will represent our graph in form of adjacency matrix*/
	Graph graph(nodes, vector<int>(nodes, 0));
	update_components(components, graph);

	cin.get();
	string input;
	while(getline(cin, input)) {
		/*Take the input in line
		* Convert it into stream
		* Parse the data to recognize the type of input
		*/	
		
		if(input=="0") break; /* Since no exit condition was there, I am assuming that 
		                        on entering 0, we exit the program */
		
		istringstream in(input);
		vector<string> parse;
		while(in >> input) {
			parse.push_back(input);
		}
		bool type = parse[0] == "a";
		if((int)parse.size() == 3) {
			int u, v;
			u = stoi(parse[1]);
			v = stoi(parse[2]);
			add_edge(graph, u, v, type);
		}else {
			unsigned long long b = stoull(parse[1], nullptr, 16);
			vector<int> bits;
			for(int i = 0; i < 64; i ++)
				if((b >> i) & 1)
					bits.push_back(i);
			for(int i = 1; i < (int)bits.size(); i ++) 
				for(int j = 0; j < i; j ++)
					add_edge(graph, bits[i], bits[j], type);
		}
		update_components(components, graph); /* keep a check on components after every update */
	}
}