# ch.8

2024/05/09

## p.2

### Internet address

모든 host는 unique한 주소를 갖는다.

IPv4: 32bit

IPv6: 128bit -> IPv4 모잘라서 만듦

-> 근데 현재 IPv4를 주로 쓴다 -> private 어쩌고로 개수 부족한거 극복

## p.4

binary, dotted-decimal notation

## p.7

ip address structure -> 3개로 나눔

## p.9

대충 첫번째 byte를 기준으로 만듦

## p.8

IANA -> APNIC -> KRNIC -> ISP(통신사)

## p.10

Network / Host 할당

A: 8 24

B: 16 16

C: 24 8

ISP에는 Network address를 할당 -> 나머지는 지들알아서

ex) 215.10.47.?(보통 0) - 클래스 C을 서강대에 받아옴 -> 나머지 컴퓨터에 ?자리 1~255 까지 나눠줌 -> 컴퓨터가 256대 이상이면? -> 클래스 B로 가야함

-> 클래스 B만 다나감 -> 대안? 클래스 C 여러개 -> 근데 가까이있으면 비슷하게 주소 할당

## p.14

### Subnetting

subnet mask의 1까지가 network, 0은 host의 위치를 표시

만약 subnet이 11111111 11111111 11110000 00000000 : 20/ 12 인경우

서강대 ip 163.239 -> 163.239.176.0 ~ 163.239.191.255 가 network addreess, 2^12개의 host, class c가 16개

-> 즉 subnetmask를 통해서 다양하게 hostnumber 개수를 조절할 수 있다.

## p.15

subnet mask가 있다보니 class 나눈게 의미가 없어짐 -> classless addressing -> CIDR

subnet mask가 있다보니 class 여러개 준것처럼 됨 -> Supernetting







2024/05/14

## p.17

규칙 3개: 연속, ip address 개수는 2의 배수, 시작지점은 개수로 나눠져야 한다.

## p.18

205.16.37.20 -> 16으로 안나눠져서 안된다.

## p.19

subnet mask 만큼의 prefix는 같은 network를 의미

## p.20

/@ -> subnet mask의 bit 수

## p.21

205.16.37.32/28 -> 205.16.37.32 ~ 205.16.37.47 의미

## p.24

### Prefix routing

ex) destination 194.24.0.0/16

194.24.83.72 로 간다고 할때

우선 prefix를 보고 이동(194.24.0.0) -> routing table을 보고 그 뒤에거로 이동(194.24.83.72)

## p.25

194.24.10.55로 가야하면 -> 우선 Edinburgh의 194.24.8.0으로 이동 (얘내둘의 첫 22비트가 일치하므로 = prefix matching)

## p.28

194.24.14.72 -> 근데 보니깐 여러개와 매칭이 되기도 함

194.24.14.72: 194.24.00001110.72

194.24.0.0: 194.24.00000.0 -> 앞에 19개 일치

194.24.12.0 : 194.24.00001100.0 -> 앞에 22개 일치

둘 다 일치하면 더 많이 일치하는 데로 이동

## p.29

### Route Aggregation

routing table은 동적으로 update 된다

194.24.0.0/21 -> 194.24.0.0 ~ 194.24.7.0

194.24.8.0/22 -> 194.24.8.0 ~ 194.24.11.0

194.24.16.0/20 -> 194.24.16.0  ~ 194.24.31.0



-> 194.24.0.0/19 -> 194.24.0.0 ~ 194.24.31.0 -> 위의 3개를 다 포함 = aggregated의 prefix는 최대한 길게

