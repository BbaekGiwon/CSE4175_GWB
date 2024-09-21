#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>
#include <queue>

/*(15) 노드의 개수는 최대 100개이며, 링크 cost의 최대 값은 100, 메시지 스트링의 최대 길이는
1000 byte로 가정하면 된다. Messages와 changes file은 100라인을 넘지 않는다. */
#define MAX_NODE 100
#define MAX_COST 100
#define MAX_MESS_LEN 1000
#define MAX_MESS_LINE 100

using namespace std;

/*message structure*/
typedef struct
{
    int from, to;
    string message;
} mess_struct;
/* routing table*/
typedef struct
{
    int next[MAX_NODE];
    int cost[MAX_NODE];
    deque<int> path[MAX_NODE];
} route;

/*routing talbe function*/
void routing_table_init(int node_num, route *route_table, map<int, int> *edge);                        /*init routing table*/
void routing_table_update(int node_num, route *route_table, map<int, int> *edge);                      /*update routing table*/
void routing_table_modify_change(int node_num, route *route_table, map<int, int> *edge, int u, int v); /*modify change*/
void routing_table_print(int node_num, route *route_table, ofstream *output);                          /*print routing table*/

/*simulation*/
void simulation(mess_struct mess_line, route *route_table, ofstream *output); /*do simulation for each message*/

int main(int argc, char *argv[])
{
    /*data structure*/
    map<int, int> edge[MAX_NODE];        /*edge: map<dest, cost>*/
    mess_struct mess_arr[MAX_MESS_LINE]; /*storing message*/
    route route_table[MAX_NODE];         /*route table*/

    /*(2) linkstate와 distvec은 다음과 같이 실행시킨다. 각 프로그램은 파일 이름 세 개를 입력 인자로 받는다. */
    ifstream topo(argv[1]);
    ifstream mess(argv[2]);
    ifstream chan(argv[3]);
    /*(10) linkstate의 출력파일은 output_ls.txt로 한다.*/
    ofstream output("output_ls.txt");

    /*(3) 프로그램에 들어가는 인자의 수가 맞지 않으면, 다음과 같은 메시지를 출력하고 프로그램을 종료한다.*/
    if (argc != 4)
    {
        cout << "usage: distvec topologyfile messagesfile changesfile\n";
        return 1;
    }

    /*(4) Input file open시 에러가 발생하면 다음과 같은 메시지를 출력한다. */
    if (!topo.is_open())
    {
        cout << "Error: open input file.\n";
        return 1;
    }
    if (!mess.is_open())
    {
        cout << "Error: open input file.\n";
        return 1;
    }
    if (!chan.is_open())
    {
        cout << "Error: open input file.\n";
        return 1;
    }

    /*(5) 프로그램 실행 성공 시 다음과 같은 메시지를 출력한다.*/

    if (!output.is_open())
    {
        cout << "Error: output_ls.txt\n";
        return 1;
    }
    cout << "Complete. Output file written to output_ls.txt.\n";

    /*(6) Topology file은 먼저 첫번째 줄에는 네트워크에 있는 노드의 총 개수가
있다. 그 다음 줄부터는 네트워크에 있는 링크(회선)에 대한 정보가 있다. */
    /**/
    int node_num;
    int a, b, c;
    topo >> node_num;

    while (topo >> a >> b >> c)
    {
        edge[a][b] = c;
        edge[b][a] = c;
    }
    /*(9) 가장 먼저 topology file을 읽어 들여서 네트워크를 구성한다. 그런 다음 link state또는 distance vector
     알고리즘을 이용하여 각 노드의 라우팅 테이블을 구성하는 것이다. */
    routing_table_init(node_num, route_table, edge);
    routing_table_update(node_num, route_table, edge);
    /*(10) 맨 먼저, changes file의 내용을 적용시키기 전, topology file에서 제시된 네트워크 토폴로지에
대하여 converge된 라우팅 테이블을 출력한다*/
    routing_table_print(node_num, route_table, &output);

    /*(7) Messages file에서는 각 줄이 하나의 메시지를 의미하며, 각 메시지의 포맷은 아래와 같다. */
    string temp;
    int mess_num = 0;
    while (getline(mess, temp))
    {
        istringstream iss(temp);
        int a, b;
        string s;
        iss >> a >> b;
        getline(iss >> ws, s);
        mess_arr[mess_num].from = a;
        mess_arr[mess_num].to = b;
        mess_arr[mess_num].message = s;
        mess_num++;
    }

    /*(9) - 그리고 난 다음, messages file에 있는 각 줄의 message를 라우팅 테이블을 통해 송신자부터 수
신자까지 전달하는 과정을 simulation한다. 여기 까지가 step 0이다. */
    /*(10) 이렇게 라우팅 테이블 출력이 끝나고 나면, messages file에 있는 메시지를 송신자부터 수신자로
    전달한다고 가정하고, 그 내용을 출력한다. */
    for (int i = 0; i < mess_num; i++)
    {
        simulation(mess_arr[i], route_table, &output);
    }
    output << "\n";

    /*(8) Changes file에는 네트워크의 상태 변화가 적혀 있다. 아래는 changes file의 한 예를 보여준다. */
    /*(9)- Step 0을 마쳤으면, changes file 첫번째 줄에 있는 상태 변화를 적용한다. 적용하고 나면 특정
링크의 cost가 바뀐다. (없던 링크가 생기거나 있던 링크가 없어질 수도 있다.)*/
    while (chan >> a >> b >> c)
    {
        /*-999 means disconnect*/
        if (c == -999)
        {
            edge[a].erase(b);
            edge[b].erase(a);
            routing_table_modify_change(node_num, route_table, edge, a, b);
        }
        else
        {
            if (edge[a][b] >= c)
            {
                edge[a][b] = c;
                edge[b][a] = c;
            }
            else
            {
                edge[a][b] = c;
                edge[b][a] = c;
                routing_table_modify_change(node_num, route_table, edge, a, b);
            }
        }

        /*(9)- 그리고는 다시 link state와 distance vector 알고리즘을 이용하여 각 노드의 라우팅 테이블을 업데이트한다.*/
        routing_table_update(node_num, route_table, edge);
        routing_table_print(node_num, route_table, &output);
        /*(9)그리고 난 다음, messages file에 있는 각 줄의 message를 라우팅 테이블을 통해 송신자부터 수
        신자까지 전달하는 과정을 simulation한다. 여기 까지가 step 1이다. */
        for (int i = 0; i < mess_num; i++)
        {
            simulation(mess_arr[i], route_table, &output);
        }
        output << "\n";
        /*(9)- 이 과정은 changes file의 맨 마지막 줄까지 네트워크에 반영이 되면 끝난다.*/
    }
    return 0;
}

/*init routing table*/
void routing_table_init(int node_num, route *route_table, map<int, int> *edge)
{
    for (int i = 0; i < node_num; i++)
    {
        for (int j = 0; j < node_num; j++)
        {
            route_table[i].path[j].push_back(i);
            if (i == j)
            {
                route_table[i].next[j] = j;
                route_table[i].cost[j] = 0;
            }
            else
            {
                if (edge[i].find(j) != edge[i].end())
                {
                    route_table[i].next[j] = j;
                    route_table[i].cost[j] = edge[i][j];
                    route_table[i].path[j].push_back(j);
                }
                else
                {
                    route_table[i].next[j] = -1;
                    route_table[i].cost[j] = INT_MAX;
                }
            }
        }
    }
}
/*update routing table*/
void routing_table_update(int node_num, route *route_table, map<int, int> *edge)
{
    /*(12) - Tie-breaking rule 2 (link-state): link state routing에서 Dijkstra's algorithm을 실행하다 보면, 각 
stage에서 SPT에 넣을 노드를 선택해야 한다. 이 때 source로부터 distance가 가장 적은 노드를 
선택하는데, distance가 가장 적은 노드가 여러 개 있을 경우에는 ID 값이 작은 노드를 우선적으
로 선택하여 SPT에 넣는다. 
- Tie-breaking rule 3 (link-state): link state routing에서도 각 노드가 현재의 경로와 새로운 경로 
중에서 어떤 것을 선택할지 판단하는 장면이 있다. 즉, 현재의 parent 노드와 새로운 parent 노드 
중에서 distance 값이 작아지는 parent를 선택해야 하는데, 이 때 distance가 같은 parent가 여러 
개 있으면 ID 값이 작은 노드를 parent로 선택한다.*/
    for (int src = 0; src < node_num; src++)
    {
        vector<bool> visited(node_num, false);

        for (int i = 0; i < node_num; i++)
        {
            int u = -1;
            for (int j = 0; j < node_num; j++)
            {
                /*j가 오름차순으로 검색하므로, Tie-breaking rule 2는 자동으로 지켜진다.*/
                if (!visited[j] && (u == -1 || route_table[src].cost[j] < route_table[src].cost[u]))
                {
                    u = j;
                }
            }

            if (route_table[src].cost[u] == INT_MAX)
                break;

            visited[u] = true;

           for (map<int, int>::iterator it = edge[u].begin(); it != edge[u].end(); ++it)
            {
                int v = it->first;
                int cost_uv = it->second;
                /*Tie-breaking rule 3*/
                if (route_table[src].cost[u] + cost_uv < route_table[src].cost[v] || 
                (route_table[src].cost[u] + cost_uv == route_table[src].cost[v] && u < route_table[src].path[v][route_table[src].path[v].size()-2]))
                {
                    route_table[src].cost[v] = route_table[src].cost[u] + cost_uv;
                    route_table[src].path[v].clear();
                    route_table[src].path[v] = route_table[src].path[u];
                    route_table[src].path[v].push_back(v);
                    route_table[src].next[v] = route_table[src].path[v][1];
                }
            }
        }
    }
}

/*modify change*/
void routing_table_modify_change(int node_num, route *route_table, map<int, int> *edge, int u, int v)
{
    for (int i = 0; i < node_num; i++)
    {
        for (int j = 0; j < node_num; j++)
        {
            if (i == j)
                continue;

            for (int idx = 0; unsigned(idx) < route_table[i].path[j].size() - 1; idx++)
            {
                if ((route_table[i].path[j][idx] == u && route_table[i].path[j][idx + 1] == v) || (route_table[i].path[j][idx] == v && route_table[i].path[j][idx + 1] == u))
                {
                    route_table[i].path[j].clear();
                    route_table[i].path[j].push_back(i);
                    if (edge[i].find(j) != edge[i].end())
                    {
                        route_table[i].next[j] = j;
                        route_table[i].cost[j] = edge[i][j];
                        route_table[i].path[j].push_back(j);
                    }
                    else
                    {
                        route_table[i].next[j] = -1;
                        route_table[i].cost[j] = INT_MAX;
                    }
                }
            }
        }
    }
}
/*print routing table*/
void routing_table_print(int node_num, route *route_table, ofstream *output)
{
    /*(10) 라우팅 테이블 출력은 0번 노드의 테이블부터 출력하며, 각각의 테이블 사이에는 공백 줄 한 줄을 넣는다.
    라우팅 테이블은 각 줄에 목적지 다음 거리와 같은 형태로 출력하면 되며, 출발지 ID로 정렬해서 출력한다.*/
    for (int i = 0; i < node_num; i++)
    {
        for (int j = 0; j < node_num; j++)
        {
            /*infinite == no route*/
            if (route_table[i].cost[j] == INT_MAX)
                continue;
            *output << j << " " << route_table[i].next[j] << " " << route_table[i].cost[j] << "\n";
        }
        *output << "\n";
    }
}

/*do simulation for each message*/
void simulation(mess_struct mess_line, route *route_table, ofstream *output)
{
    /*(10) message에 대한 출력 포맷은 다음과 같다. 만약 송신자 x로부터 수신자 y로의 경로가 존재한다고 하면,
from <x> to <y> cost <path_cost> hops <hop1> <hop2> <...> message <message>
만약 송신자 x로부터 수신자 y로의 경로가 존재하지 않으면, 다음과 같이 출력한다.
from <x> to <y> cost infinite hops unreachable message <message>*/
    int cur = mess_line.from;
    int dest = mess_line.to;

    *output << "from " << mess_line.from << " to " << mess_line.to;
    if (route_table[cur].cost[dest] == INT_MAX)
    {
        *output << " cost infinite hops unreachable message " << mess_line.message << "\n";
    }
    else
    {
        *output << " cost " << route_table[cur].cost[dest] << " hops ";
        for (int idx = 0; unsigned(idx) < route_table[cur].path[dest].size() - 1; idx++)
        {
            *output << route_table[cur].path[dest][idx] << " ";
        }
        *output << "message " << mess_line.message << "\n";
    }
}
