# ch.6

## DATA LINK - Multiple-access resoultion

2024/04/18

## p.4

point to point: 모든 페어에 대해서 연결 -> nC2

shared: 철수한테 보내는데 영희도 거쳐가는거 (엄한놈 거쳐갈 수 있는거)

요즘은 허브에 다 붙어있데

## p.5

공유하는 경우 -> 누가 말하는가가 중요 -> 동시에 말함 섞임 ->

와이파이 -> 여러 명이 동시에 받는 경우 -> 남의거는 noise -> SNR 낮아짐 -> 동시에 안쏘면 되는거 아님? -> 차례차례 쏘도록 만들기

전자레인지도 2.4GHz라는데?

## p.7

### Random access protocols

<-> control access

충돌을 무작위로 피한다. -> 와이파이

누군가가 동시에 접속하면 둘다 잠깐 멈추고 기다린다(이부분이 random).

## p.8

### ALOHA

보낼라믄 보내고, 충돌하면 랜덤 시간만큼 기다린다.

## p.9

Frame 전송할때 충돌 발생 -> 수신자가 못받음 -> 송신자가 알아야함 -> ACK, time out -> 그러면 다시보내는데 random하게 기다린 후 

## p.10

Frame 1.1, 3.2 성공, 겹친거 날라감 -> 효율 구림

## p.11

Frame이 날라감 -> timeout -> 얼마나 기다려야 하는가? -> (0~2^(k) -1) * T -> 또 충돌 -> 범위를 2(k)배로 늘린다.

아니 그럴거면 처음부터 많이 기다리지 -> 근데 몇명이서 기다리는지 모름 -> 고로 늘려가는게 나름 합리적

## p.12

여기서는 k가 커지다 max가 되면 걍 포기

## p.13

Time slot T = Transmission + propagation time -> 둘 중 긴 것을 더 고려

Transmission time >> propagation -> 거리가 짧다, bandwidth가 작다, frame 크기가 크다

## p.16

T_p가 작다고 가정, T_fr만 고려해보자 + T_fr이 같다

A 보내고 있을때 T_fr + T_A 시간동안 전송을 시작하면 안된다. -> Vulnerable time

푸아송 분포 -> 평균적으로10초동안 10대 지나갈때 5대 지나갈 확률

-> p(k) = (e^-ㅅ * ㅅ^k) / (k!) 

-> k개의 event가 발생할 확률 p(k) , ㅅ: 평균발생 event 수, G: 한 T_fr 동안 평균적으로 전송되는 프레임 수 <- 2*G = ㅅ

p(0) = e^(-2G) -> 이 기간동안 하나도 안보내야 충돌 X

S = G * e^(-2G)

## p.20

T_fr = (Frame Size) / (Channel Bandwidth)

200bit / 200kbps = 1ms

## p.21

1ms에는 0.5frame -> G = 0.5 -> S = G * e^(-2G) 

고로 500 * 0.184 = 92가 살아남는다.

## p.22

Slotted ALOHA: 암때나 못보내게 함 -> slot으로 나눈뒤 slot이 시작할때만 전송 가능 -> vulnerable 타임이 줄어든다. T_fr로 줄음  -> S = G * e^(-G)







2024/04/30

## p.24

ALOHA는 무지성 말하기, CSMA는 일단 들어보기

## p.25

sensing을 해서 signal이 있는가 없는가 판단

-> 두가지 상태 도출

* idle(유휴상태) - 비어있다

* busy(통화중?)

이 두개를 어떻게 구분? 일정 dbm을 기준으로 이분법 -> 있어도 약하면 걍 보냄

## p.27

ALOHA 보다는 충돌 가능성이 줄어든다 -> 그럼 충돌을 아에 없는가? -> 그건 ㄴㄴ -> 동시에 말하기 시작하면 충돌 on

## p.28

B가 보냄 -> B가 보낸 것을 C가 알기까지 시간이 걸림(t2-t1)

t1: B가 sensing -> idle -> 전송

t2: C가 sensing -> idle -> 전송 -> collision

## p.29

vulnerable time = propagation time

## p.30

그럼 ALOHA가 vulnerable time이 짧을 수 있지 않을까? -> 이거는 transmission time이 propagation time보다 짧다고 생각해서 propagation time은 고려안함

똑같은 논리로 CSMA는 transmission 보다 propagation이 길다고 생각함

## p.31

### 1-persistent CSMA

busy인 동안 계속 sensing -> idle 되자마자 전송

-> 근데 나만 기다리는게 아니잖음

## p.32

### Non-persistent CSMA

busy인 동안 계속 sensing 하지 않고 조금씩 랜덤으로 띄엄띄엄

-> 충돌 확률은 줄어들지만 기본적으로 좀 느리다.

## p.33

### p-persistent CSMA

busy인 동안 계속 sensing -> idle 되면 p의 확률로 전송 -> 안되면 일정시간 기다림 -> 다시 sensing

-> 절충안

## p.35

### CSMA/CD

CSMA + collision detection

이더넷에서 쓴데

## p.36

A: t1에 전송 시작 -> t4에서 뭐 딴거 받음 -> 이때까지 보내고 있었으면 충돌 감지 ㅇㅇ

C: 보내고 있었는데 딴거 받음 -> 충돌 감지 & 그만보냄

## p.37

A 입장에서 C 받기전에 전송을 다끝냄 -> 이건 충돌 아니지 ㅇㅇ -> 근데 충돌이 일어나긴 함 -> 즉 너무 짧게 전송하면 충돌을 감지 못하는 상황 발생 -> 어느정도는 길게 frame을 가져가야 한다.

ex) 최악의 충돌경우, Tp =  propagation time

A가 t1에 전송시작 -> B가 t1+Tp에 전송시작 -> A는 B의 것을 t1+2*Tp에 받음 -> 최악의 경우 2 * Tp동안 전송한다면 충돌 감지 가능

## p.38

T_fr >= 2 * Tp

Frame Size(bits) / Channel Bandwith(bps) = distance / speed -> 이 중 Frame Size만이 조작 가능하다 -> 즉 보낼게 몇개 없어도 억지로 할당량을 채워야 한다.

즉 최소 프레임 사이즈가 존재한다.

## p.42

Tp = 25.6 us -> T_fr >= 51.2 us -> Frame Size / Channel Bandwitdth >= 51.2 us -> Framw size >= 512 bit

## p.43

충돌이 나면? -> random time 기다렸다가 다시 전송 = ALOHA와 유사하다.

binary exponential backoff -> 기다리는 시간이 2배씩 늘어난다.

## p.44

### CSMA/CA

이건 wifi에서 씀

half-duplex여서 이거 써야함 -> 한번에 보내고 받는거 하나씩만 가능 -> 무선과 유선의 차이

동시에 수신 송신을 해버리면 송신하는 것을 바로 수신해버림 -> 오류

서로 다른 체널을 쓰면 동시에 송수신 가능 -> 주파수는 돈인데 이렇게 하기에는 아까움

어쨋든 이래서 CSMA/CD를 못쓰고 CA를 씀 (collision detection이 안된다 -> 고로 avoid한다)

## p.45

frame 손실 -> collision or 거리가 멈 -> 구분이 안되므로 무조건 collision으로 처리

## p.46

### IFS

busy에서 continuous sensing -> idle -> 바로 쏘면 오류나니깐 더 기다림 = IFS(고정된 시간 기다림) -> binary exponential 기다림(남들도 다 fixed 기다렸음, 추가로 더 기다려야 함) -> 이제야 보냄

## p.47

### Contention window

무작위 숫자 선정 -> 이게 줄어들때까지 기다림 -> 근데 갑자기 busy 됨 -> sensing -> idle -> IFS -> 전에 기다리다 남은거 마저 기다림

충돌이 발생하면 무작위 선정 범위 두배, 이것도 범위 제한 있음

## p.50

문제에서는 Frame Size 같다고 가정

ps) broad cast는 ACK이 없다.

​              |50|  250          |350 |400|          500               |600|650|             750             |850|

A:|busy|IFS|200기다림|전송|

B:|busy|IFS|200기다림|busy|IFS|5*20남은거기다림|전송|

C:|busy|IFS|200기다림|busy|IFS|    남은거 기다림    |busy|IFS|5*20남은거기다림|전송|







2024/05/02

## p.55

### Controlled Access

random 의존 X

## p.56

### Reservation

규칙성을 가지고 함

정해진 시간에 보내기 -> 근데 이러면 안보내면 낭비 -> Reservation -> 예약 시간을 가진다 -> 조그마한 정보를 보냄 -> 예약한대로 차래대로 전송 시작

추가, 제거할때 번거로움 -> reservation slot을 할때마다 변경 필요 -> 고로 개수가 고정일때 유용

## p.58

### Polling

primary & secondary

Select: primary가 보낼때

primary가 Select를 보내고 ACK 받으면 data 전송 시작

왜 굳이 Select를 보냄? -> 처음부터 data 보냈는데 못받으면 비효율적, data는 길지만 Select는 짧으므로

Poll: primary가 받을때

받을게 있을 때: Poll -> Data -> ACK

없을 때: Poll -> NAK



primary가 날라가면 system 자체가 망가짐

## p.60

### Token Passing

Token을 돌려쓰면서 있으면 전송 

Token이 날라감 -> 누군가 보냈었다는 정보 있어서 복구 -> 복구 안되면 좆망

Token 잘 보냄 -> 근데 ACK을 못받음 -> 날라간 줄 알고 복구함 -> Token 두개 돼서 충돌 조짐

## p.64

### Channelizaiton

이러나 저러나 충돌나니깐 자원(주파수, 시간)을 나누자

## p.65

### FDMA

Frequency Division Multiple Access

꼭 균등하게 나눌 필요 X -> 많이보내면 더 많이 할당

## p.66

주파수 나눌때 조금씩 띄어서 할당해야함 = guard band

ex) 20MHz -> 1MHz의 sub channel로 나눔 + guard band 100kHz -> 18개로 나누는개 최선

Guard band는 줄이지 못하므로 단점이 존재한다.

## p.67

### TDMA

Time Division Multiple Access

이것도 Guard interval 존재

## p.68

FDMA vs TDMA

시간이 좀 더 다이나믹하게 바뀔 수 있다. 

근데 요즘은 둘다 활용해서 나눈다.

## p.69

### CDMA

Code Division Multiple Access

섞인 상태에서 구분

c = 접속할때 부여 받는 고유 코드(벡터)

d= data

## p.74

c끼리 내적하면 0이지만 자기 자신과 내적하면 4

## p.75

data 를 보낼때 c와 내적 -> 그 값들을 다 더함 -> 모두에게 전달 -> 받은쪽에서 보고 싶은거(송신자)의 c값을 더한거랑 내적 -> -4면 0bit/ 4면 1bit/ 0이면 silence 였던거임

## p.80

코드값의 개수는 2^n으로 한다. ex) 11명이여도 16개

확장하는 방법 알기

확장 후 어차피 sym 하므로 대충 row를 따든 col vector를 쓰든 노상관
