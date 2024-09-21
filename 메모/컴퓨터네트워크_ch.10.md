# ch.10

2024/05/21

## p.5

들어오는 데이터를 가야되는대로 내보는거 -> Forwarding

아무데나 내보내면 안되니까 어디로 나가야하는지 계산 -> Routing

## p.6

data plane: data 오가는거

## p.8

control palne: 어떻게 forwarding을 할지? = routing algorithm -> 동적임, 새로운게 생기고 없어지고 함

전통적으로 routing algorithm이 기기마다 있다 -> 나중에는 data plane이 router에만 있고 control plane은 서버에 있는 경우

## p.11

forwarding table: 어디로 갈라면 어디로 나가야 하는지

## p.19

방식

intradomain

* distance vector
* link state

interdomain

* path vector

Protocol(무슨 bit는 무슨의미인지 정해진거): RIP, OSPF, BGP

## p.20

Intra-domain vs Inter-domain

하나의 관리주체가 관리하는 망 = domain

고로 domain 마다 routing이 다르다 -> domian 끼리 소통은 표준화된 것만 가능

autonomous-system: 어떤 지역을 담당하는 routing

## p.21

### Autonomous System(AS)

intra: AS안에서

inter: AS끼리

gateway router: 내부 외부 연결

## p.28

### Distance vector

A,B,,,: IP 주소 block

## p.32

D->E한데 정보전달

E: C가는길 추가

## p.34

B->A 정보전달

A: C가는 길 추가, E는 업데이트 안함

## p.38

내 테이블 정보를 이웃에게 전달 -> 주기적 & update 되면 전송

## p.40

routing protocol의 장점: 변화가 생기면 update가 잘됨

E <-> D 끊어졌을 때, cost 바뀌면 -> 다시 table update

## p.43

### Count-to-infinity

서로를 거쳐가야되는데 끊어진거 모르고 계속 update하는 경우

B: C가 준 최소거리가 나를 거쳐가는건지 모름

## p.50

### Split horizon

C가 다음이 B인것은 정보를 안보낸다

with poision reverse: 다음이 B인것을 거리가 무한으로 해서 보낸다

## p.51

근데 해결이 안되기도 한다.

D는 D->C->B->A로 갈때 B입장에서 D가 A갈 수 있다고함, D가 A가는것의 다음은 C이므로 B한데 보내줌

->근본적인 해결책 X

## p.52

### Path vector routing

근본적으로 경로를 다 기억하면 된다

그럼 인터넷 주소에 경로를 다 써야함 -> routing table이 커짐 -> 오버헤드 발생









2024/05/23

## p.56

읽어보기

## p.57

### Link state routing

link state 나와 인접한 애들의 정보 -> 네트워크 전체에 뿌린다(forwarding). -> 전체 그래프 파악 가능 -> shortest path 구하는게 가능(Dijkstra algortihm)

## p.61~65

읽어보기

다음 step을 고를때는 가장 작은 값을 고른다.

## p.68

flooding: broadcast 하는것과 유사, 받아서 모두에게 보냄 -> 잘못하면 불필요하게 많이 전송,수신 가능 -> 대안(sequence number-보내다보면  옛날 버전이 나중에 오기도, 곧이 곧대로 업데이트하면 문제 발생)

163.239.26.0/24 <- 256개 포함, 근데 @.@.@.0, NULL @.@.@.255는 broadcast(prefix내 모든 라우터에 뿌리는 일)

## p.70

### OSPF

Link-state ID: 보낸놈

Link ID: 마지막놈

Link data: 번호 붙이기

Metric: cost

## p.72

Link state: 이웃정보를 모두에게

Distance vecotr: 모두 정보를 이웃한데

## p.74

intra: 내부라서 성능 중요

inter: hierarchical, 돈 중요

## p.76

규모 순: Tier 1 > 2 > 3

Tier 1: 전세계

Tier 2: 나라 단위 -> 전세계 소통할때는 Tier 1 주고 소통

Tier 3: 얘도 위에 돈주고

같은 티어는 협약

multi-homing: provider 여럿

## p.78

RIP, OSPF -> 큰거에는 부적합 -> BGP으로 대체

## p.79

### BGP

Gateway router는 inter, intra 둘다 돌림

eBGP: 바깥으로 가는 놈 

iBGP: 안에서 도는 놈

## p.80

어디로(Prefix) 갈라면 어디(Path)를 거쳐야 하는지

path가 여러개 이기도

## p.81

route advertisement = distance vector routing

일단 받아보고 route를 보고 내가 포함되어있으면 버린다 -> loop 방지

## p.82

AS 500에 있는 300 200 100은 100한테 보내봤자 루프 생겨서 버리므로 안보냄

즉 loop방지는 두가지 1. 받아보고 loop면 버림 2. 보내봤자 loop면 안보냄

## p.83

### iBGP

internal

## p.84

같은 AS에 속한 라우터(R1, R2), 

fully connected: 경유X, 모두 직접 연결

즉 내부에 있는 거끼리는 경로를 말해주지 않는다 = 내부에 경유를 허락하지 않는다

외부에서 온것만 전달해준다.

## p.86

아무 path나 traffic이 지나가지 않는다.

티어를 올라간 뒤 내려가는 것만 가능, 티어 와리가리 불가능







2024/05/28

## p.86

계약에 의해 갈수 있고 없고가 정해짐

routing advertisement 땜에 위아래 와리가리 안된데

## p.87

customer에게는 내가 가진 모든 path를 알려줌

provider에게는 customer만 알려줌

peer한데도 customer만 알려줌

즉 peer는 두단계 뛰어넘는거 불가

tier 1끼리는 서로 peer임

## p.88

provider가 여럿

preference를 설정해서 더 높은 값쪽으로 감

## p.89

받는거가 여럿

이건 작은놈이 우선순위
