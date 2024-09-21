# ch.13

2024/06/04

## p.2

### Transport Layer

layer 3에서는 destination이 IP

End-to-end(process-to-process) -> IP + PORT -> ip가 같아도 구분이 된다.

## p.6

### Port

process to process 통신에서는

– local host

– local process (port number) 

– remote host 

– remote process (port number

가 필요하다

## p.7

traffic의 종류는 2개로 나눌수 있다

Client-Server: client가 먼저 요청, server는 대기 -> server는 정해진 포트 넘버 필요, client는 지가 알아서 배정

Peer-to-peer: 토렌트 같은거, 누구나 서버 가능

daytime server에게 뭘 보낼라면, 포트넘버를 알아야 한다

## p.8

IP & Port 둘다필요 -> IP까지 간뒤 어디로 갈지? -> Port

## p.9

포트 넘버도 나름대로 의미가 있다

well-known ports: (http: 80, https: 443, ssh: 22)

registered ports

dynamic ports

## p.10

### Socket

통신을 위한 자료구조

ip정보로 서버까지 간뒤에 demultiplexer를 거치고 TCP 프로토콜에 따라 process ??

## p.12

TCP: 통신하기 전에 우선 연결, reliable

UDP: 일단 보내고 봄, unreliable

## p.13

layer 2에서 error control을 하지만 또해야함

destination unreachable, buffer가 꽉차거나, TTL==0 등으로 drop 된다면 layer 2에서 검출하지 못하는 오류다 -> 이런거는 TCP만

## p.19

### UDP

header

source port, destination port -> demultiplex할려면 필요한 것들

length, checksum

proccess만 구분해줌

그럼 이거 어따씀?







2024/06/11

## p.21

UDP는 뭐 있는게 없다 -> 걍 보내기만 함, 오류 체크 X(sequence number X)

## p.22

그럼 UDP 왜 씀? -> 동영상, 실시간 스트리밍 -> 이런거는 reliability 보다 실시간이 중요하다

(멀티미디어)코덱: 중간 packet 날라감 -> application level에서 이을 수 있다. -> 고로 TCP 불필요

## p.25

### TCP

connection-oriented protocol: 선 연결 후 통신

reliable delivery: 오류 체크, 재전송 해줌

## p.26

byte stream: 각각 byte에 넘버를 붙임(header)

## p.27

비동기적으로 -> buffer에 쌓아둠 -> 주고 받는데 속도차이 가능

## p.28

segment -> TCP에서 쓰는거, byte stream + head

유사 packet 임

## p.29

bi-directional이다

## p.30

byte number -> sequence number -> 고로 옆에 sequence는 꼭 숫자가 붙어 있지 않아도 된다.

ACK는 마지막 byte 다음거

## p.35

* Flow control: 속도 조절
* Congestion control: network 고려 속도조절
* Error control: 다시 보내줌

## p.36

### TCP header

반드시 20byte 이상

optino 붙이면 60 byte 까지

## p.37

bidirectional: ACK을 받는다 -> ACK은 header만 있어도 된다 -> 근데 서로 주고 받을 정보가 있을 때, data랑 ACK를 한번에 보낸다.

## p.39

push: buffer 전송

rst: reset 재시작 -> 뭔가 문제가 생기면 server가 client한테 보냄

syn: 1일 경우 connection setup 과정

fin: 1일 경우 통신 끝날 때

urg: urgent,1일때 & urgent pointer가 뭔가를 가르킬 때, 원래 있던거 무시하고 얘 먼저 -> 끝나면 urgent pointer위치 부터 다시 시작

## p.42

window size: 16 bit -> receiver의 남은 버퍼 byte -> 이거에 맞게 보냄

## p.45

S -> A, S -> A -> 이제 양방향 통신 가능

S = connection setup -> 얘를 주고 받고 A도 받으면 끝

정보를 안보낼 때 seq num은 노상관 -> 고로 ACK 만보내니까 걍 seq = 8000임, data 보내면 다음 부터

## p.47

DoS: 남도 못들어가게 하기

서버로 커낵션 요청 = SYN 보냄(fork로 많이 보냄) -> 그리고 내가 ACK을 안보냄 -> 서버는 ACK이 오기전까지 기다려야 함 -> TCP request buffer를 꽉 채운다. -> 방화벽이 ip 차단함 -> 그럼 header의 ip 주소를 바꿀 수 있다.(스푸핑?) -> 역추적 -> 좀비 pc 만들기

## p.48

종료도 3way로 간다

A,F -> A,F -> A

## p.49

half-close: server가 더 보내고 싶을 때, 우선 데이터랑 A만 보내고 나중에 F를 보내는 것









2024/06/13

## p.52

### TCP siding window

한번에 하나 주고 받고 그다음에 보내면 느림 -> 한번에 보내고 한번에 받기 

window 안에 있는 거는 ACK을 못받은거

ACK를 못받은 것 개수 상한선 컨트롤

## p.57

200, 201, 202 ACK 받음 -> window 오른쪽으로 3칸 이동(sliding) -> 209,210,211 window 안에 = 보낼 수 있다.

## p.53

send

- LastByteAcked: sent the byte, received ACK 
- LastByteSent: sent the byte 
- LastByteWritten: application sent the byte to the TCP 
- LastByteAcked ≤ LastByteSent ≤ LastByteWritte

## p.54

recieve

*  LastByteRead: application read the byte from TCP
* NextByteExpected: byte must be received from the sender, 젤 중요, 그 앞에까지는 다 받았다.
* LastByteRcvd: last byte received (disregarding missed  bytes)
* LastByteRead < NextByteExpected ≤ LastByteRecv + 1

## p.56

window의 크기? -> 전송속도 좌우

최적의 크기: 보내고 ACK을 받는 기간동안 계속 보낼 수 있을 만큼의 window, 속도조절&안놀게

고로 window size = min(rwnd, cwnd)

## p.59

advertised window(rwnd) = 4000

## p.60

window size = 3000

## p.64

window size -> 통신속도에 영향

보내는 속도가 너무 빠름 -> route, 목적지에서 drop -> 재전송 -> 근데 조절 안되면 또 날라감 -> 오히려 전송속도 낮아짐

wifi 느린 경우가 이런거 -> wifi가 받는게 많아서 drop

보내는게 느리면 -> 놀아버림

## p.67

TCP header에 window size 16bit -> 작다 -> option을 사용하자

## p.68

window bit 모두 1 = 65535

option에 들어있는값 n -> 2^n (n<=14)

window size = (window bit) * 2^(option), 

## p.69

### silly window syndrome

receiver가 거의 꽉참 -> 나 10 byte 남았음 -> 그럼 10byte 보내야지 -> 근데 이 10byte 안에 header 오지게 붙음 -> data 대비 header가 크다

## p.70

보통 1460 byte -> header 까지 합쳐서 1500(MTU)로 맞춤 -> fragmentation하기 귀찮

## p.71

* Nagle’s algorithm (sender): 너무 작으면 안보냄, 실시간에는 방해될수도, MSS보다 클때만 보냄, 타이머도 있음
* Clark’s algorithm (receiver): 너무 작으면 0이라고 advertise window

## p.74

### Congestion

라우터의 병목현상 -> 얘 layer 4가 없어서 문제 생겼다고 말 못함

load: 트래픽 양

dealy: 들어오고 나가기까지의 시간, 시간이 너무 길어진다 -> drop하기 시작 -> 그게 congestion

Throughput: 전송량, load가 늘면 얘도 늘어남, congestion을 지나면 drop -> 그럼 재전송 -> 그러면 throughput 감소

## p.77

congestion area를 어떻게 찾냐 -> 귀납적으로 -> 조금씩 늘려가면서 보내봄 -> drop 될때까지

-> 이것의 가정은 congestion만 packet loss가 난다고 가정 -> 이때는 유선만 있어서 가능 -> 무선 생김 -> 동굴들어가면 혼자여도 congestion 난줄 앎

## p.78

그래서 control 어케함?

처음에는 한 RTT에1MSS로 잡음 -> ACK이 오네? -> 한 RTT 2MSS(exponential하게) -> ... -> packet drop 발생할 때까지

## p.83

timeout 발생!

SSThresh: 실패하기 바로직전 

CWND = 1이됨 -> 증가하다가 SSThresh에 도달하면 linear하게 증가(1RTT 당 1MSS) -> slow start라는데

CWND += MSS * (MSS / CWND)

## p.87

결론적으로 이렇게 생김

## p.88~96

넘어감

## p.97

### Fast Retransmission

timeout 범위가 크다

## p.99

2 오류 -> 3,4를 보내도 next expected bit = 2, 2달라고함

근데 1에서 ACK(2)는 인정임 ㅇㅇ

허나 3, 4 는 중복으로 온것

이렇게 중복으로 3개가 오면 packet loss로 판단

## p.102

time out, three duplicate ack -> 둘의 처리방법을 다르게 하자

time out은 반으로 짜르고 1로 떨구는 거

three duplicate ack -> 반으로 떨굼 -> 바로 congestion avoidance

time out은 duplicate ack을 보내줄 애도 없이 다 날라간거 -> 좀 더 심각하므로 처음부터 다시 시작해

three duplicate ack 그래도 몇개는 갔음 -> 반절로만 줄이자(fast recovery)

fast retransmission -> time out까지 안기다리고 다시보내므로 빠르다!

## p.105 ~

넘어감

