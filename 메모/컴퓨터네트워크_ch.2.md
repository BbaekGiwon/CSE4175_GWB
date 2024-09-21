# ch.2



2024/03/19

## <p.4>

Line Coding: binary를 digital signal로 바꾸는 것

## <p.6>

정확하게 말하면 올라가는게(ㅢ) 1(, 내려가는게(ㄱ) 0이다. <- ????????? 일단 적었는데 뭔지 어딘지 모르겠음

r = # of data elements / # of signal elements

## <p.7>

Data transmission rate - bps

Signal transmission rate - baud

## <p.10>

Unipolar Encoding: 단극

NRZ: 0=0V(zero volt) & 1=@V(high volt)  <- 반대여도 노상관

## <p.11>

Polar Encoding: 양극

NRZ-L: 0,1 둘다 다른 전압으로 하겠다.

NRZ-I: 바뀌면 1, 그대로가면 0 / 1001110

## <p.14>

DC Component: 직류(frequency = 0)

준위가 바뀌지 않고 계속 일정한 부분

clock drift: 컴퓨터안에 클락 존재, 클락에 따라 동작함, 

0100 보냄 -> 수신자 받음 -> 복원 -> 0100 인식(클락을 기준으로 잘라내서 그 값 파악)

01111111111 보냄 -> 받음 -> 복원 하다가 클락이 조금 다르다면 1의 개수를 다르게 복원 가능성 -> clock drift임

즉 DC Componenet가 직접적으로 clock drift를 일으키지는 않는다. 또한 클락이 조금 달라도 010101같은 신호면 스스로 클락을 조정한다. 즉 클락도 다른데 DC Component도 있으면 문제가 발생한다.

## <p.15>

Baseline(평균값 기준선) wandering

row, high가 있음 -> 근데 얼마만큼이 row, hight인지 모름 -> 평균내서 높은거 high 낮은거 low로 때리면 됨.

근데 011111111111이 들어오면 평균이 많이 높음 -> 신호 왜곡됨 -> 잘못 해석 가능

무조건 DC Component있다고 해서 baseline wandering이 발생하지만은 않음. 

## <p.12>

NRZ-I: 011111111111111111들어오면 위아래 와리가리 오지게 함 -> 위 아래 균형 맞음/딴걸로 하면 치우침(NRZ-L)

Line coding은 위아래 균형을 맞추면서 coding하는게 좋다.







2024/03/21

self synchronization 좀 공부해보자 -> 수신자가 스스로 싱크 맞추는 것

## <p.19>

Line coding 방법 다양 필요 -> basline wandering or clock drift 피하기위해

### RZ

계속 0으로 돌아오도록

전송속도 1/2됨

 self syncronize 가능

signal level 3개인데 전송속도는 늘지 않음(특정 범위 내 준위를 쓰는 것이기에 복원 정확도 줄음)

baseline wandering 해결 X

## <p.21>

### Manchester(,differential)

ㄱ모양이 0, 반대가 1

시그널 두개만 사용 -> 복원이 쉬움

전송속도는 1/2 (=RZ)

DC component X

Baseline wandering X

Clock drift X

## <p.24>

### AMI (Bipolar)

1이 위아래 왔다갔다.

A scheme to remove DC component -> 얼추 맞음 -> 0준위가 반복된다면 DC component 아니라는데?

self synchronization은 해결 X

## <p.25>

### Pseudo-ternary encoding

1 = 0V, 0이 왔다 갔다.

## <p.27>

### 2B1Q

2bit를 1개의 4준위로 표현 (B=2,T=3,Q=4)

표보고 따라하면됨 - 0으로 시작하면 +-그대로, 1은 뒤집음

DSL

## <p.28>

8bit를 6개의 3준위로 표현

최대한 +,-균형을 맞춤 -> +,- 개수 차가 1개 이하로

two back-to-back = 한번 + 나오면 뒤집는다. (균형맞추기위한 맥락)

## <p.29>

### MLT-3

next bit = 0 -> 변화 X

next bit = 1 -> 짤보고 판단하자

## <p.30>

self-synchronization 해결 X <- 0 계속나오는 경우

준위 3개 & 바꾸는 방법 복잡함

basline wandering 피할수 있음

장점: fundamental frequency 가 1/4이 된다. <- 특정 모양을 잘 만들면 속도 4배까지도 가능

전 챕터에서 fundamental frequency는 1/2이 최소이다. (f하나만 쓴다할 때 010 보내는 것이 사인파 3/2만 쓰면 되므로) <- 이 방법은 general한 경우

## <p.31>

### Block Coding

0이 계속나오는 문제를 해결하기위해 만들어짐

Goal: self-synchronization, error detection,

## <p.32>

### 4B/5B

4bit를 5bit로 바꿔서 전송

5bit을 4bit로 바꿔서 수신

NRZ-I의 synchronization 막기위해 선 4B/5B

## <p.34>

5bit를 2/3 bit로 나눔, 앞 뒤 모두 최소 1하나를 포함한 패턴으로만 -> 가능개수:21

이렇게 하면 0이 연속으로 나오는 최대 개수 -> 3

=> NRZ-I에서 self-synchronise 문제 해결!

but 전송률이 80%이다.

## <p.36>

self-synchronise 문제를 해결해보자

* manchester -> 속도 1/2
* 4B/5B & NRZ-I -> 속도 4/5 => 의미가 있다.

4B/5B: 0 연속 4개 막는거

6B/7B: 0 연속 5개 막는거

-> 즉, 이런것들을 고르는 기준은 0의 연속을 몇개까지 허용해도 되는가?

-> 전송속도와 전송율의 trade-off

## <p.37>

### Scrambling

AMI 특화, 전송률 감소없이 0 연속을 막을 수 있다.

## <p.38>

V: 룰을 어기면서 0연속을 없앤다.

## <p.40>

### HDB3

0준위 아닌게 짝수 -> B00V

0준위 아닌게 홀수 -> 000V







2024/03/26

## <p.43>

LAN: 와이파이 기지국 - 기지국에 연결한 사람들

WAN: 기지국 - 구글

->딱히 구분이 빡세지는 않음

## <p.44>

IEEE: 표준협회 802(LAN 표준)

802.3: Ethernet

802.11: Wi-Fi

## <p.45>

cat = catagory -> bandwidth가 바뀐다.

## <p.46>

앞에 붙는 숫자가 속도(Mbps), 

twisted pair - 선 종류

full-duplex - 양방향 통신

## <p.47>

100 보내야함 -> 4B/5B라서 125필요 -> MLT-3이라서 1/4만 필요 -> 즉 31.25필요 -> cat5적합

## <p.49>

analog -> digital conversion / 음악같은거

## <p.53>

### Sampling

period 과 rate는 역수

## <p.54>

### Nyquist theorem

대충 샘플링을 많이 할수록(rate가 클수록) 복원 용이 -> but 전송용량 커진다.

maximum frequency의 두배는 sampling 해줘야 들을 만하다.

만약 이거를 못넘으면? -> aliasing 발생 ->

## <p.56>

minimum sampling rate = 8,000

## <p.57>

minimum sampling rate = 400,000

## <p.61>

### Quantizing

-6.1은 어떻게 표현함? -> float, double과 같이? -> 이러면 하나당 8bit

quantization level -> 몇개로 나눌지(ex)5~10은 같은 level로 보겠다)

파일크기(필요한 전송속도), 음질은 sampling rate와 quantization level이 결정

보통 16bit/44.1kHz

ex) 3분 44.1kHz로 쪼개고 16bit으로 encoding 하자

-> 180 * 44100 * 16 / 8 = 15,876,000 = 15Mb

요즘 고음질 24bit -> 근데 체감상 별로 모름 -> 왜? 누

## <p.62>

1bit 증가할 수록 SNRdb 6.02정도 늘어난다.

## <p.65>

Encoding: level을 bit 패턴으로 바꾸는 것

스트리밍 한다고 생각하면: 44100 * 16 = 700,000 정도를 1초에 보내야함

## <p.67>

sampling rate : 8000, 8bits

8000 * 8 = 64,000

## ㅇㅇㅇ

나머지는 넘어감
