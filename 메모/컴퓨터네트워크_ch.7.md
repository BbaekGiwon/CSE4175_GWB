# ch.7

2024/05/02

## p.2

n -> ac -> ax -> be

4  ->  5  ->  6  -> 7  세대

## p.3

Wi-Fi 표준 - layer 1,2만

layer 3는 유무선 상관 없이 작동

layer 1에 따라 2가 설계되므로 함께 따라다닌다.

## p.4

802.11 -> 무선 랜 표준

b -> g : c,d,e는? 잡다한 기준도 많다, mainstream이 g인 거임







2024/05/07

## p.8

신호감쇠

TX -> RX: 원으로 쏘기 때문에 모든 방향 -> 낭비? -> 지향성 안테나(방향 O)

## p.10

### Pathloss

신호감쇠

P_r, P_t: 신호세기

R: distance

신호의 세기는 거리의 n승 분의 일에 비례

제곱: 뭐 도시면 더 세게 쏘고(세제곱, 네제곱...) 이런거

ㅅ: 파장이 짧으면 P_r 커진다. /낮은 주파수 -> 신호감쇠 적음

G_r, G_t: 안테나가 받은거

## p.11

Receiver sensitivity: 얼마나 잘 감지 하는지

이걸 넘겨야 신호를 받을 수 있다.

## p.12

Recevier sensitivity를 넘겨도 SNR 기준치(depends on modulation & coding)도 넘겨야 함

같은 와이파이 이용-> 간섭 -> interference(같은 시스템 내일 때만)

나머지는 noise

SINR - Signal to Interference & Noise Ratio

## p.14

### Fading

* Slow fading: 장애물 때문에 느려지는 거
* Fast fading: 직통으로 신호가 오면 Line-of-Sight // 벽에 부딫혀서 오는 애는 조금 늦게 들어옴 -> 신호마다 시간 오차가 존재 -> 근데 만약 동시에 들어오면? - 증폭, 조금 엇갈려서 서로 상쇄도 가능 -> 즉 방안에서 몇 cm안 움직여도 빨라졌다 느려졌다 한다.

## p.16

신호감쇠 3대장: pathloss, fast & slow fading

## p.19

### Modulation

채널 번호 존재 -> Ch1: 2402-2422 / Ch2: 2407-2427/ ...Ch6: 2427-2447 -> 중심주파수는 가운데

20MHz

체널끼리 겹침 -> Ch1, Ch6, Ch11 이런식으로 해야 안겹침

## p.23

coding rate = 3/4 -> data: 75%, ECC: 25%

## p.24

### MCS

이름같아도 coding rate가 다르다.

MCS가 높으면  높은 SNR 필요

## p.26

### MIMO

요즘은 송수신자 둘다 안테나 여러개 사용 

여러개니깐 감쇠에 강하다 = SNR이 높아진다. -> diversity gain

array gain: 같은 주파수에서 다른 내용 -> 받고 나서 분리 -> 전송 속도 배로 향상(n개 에서 다른거 보내면 n개의 수신 안테나 필요 - p.28)

더 빠른 통신: 모듈을 바꾼다 - SNR 높아야함, Coding Rate 를 줄인다 - 오류나면 큰일 남, 고로 안테나 수를 늘리는게 제일 낫다

## p.29

physical layer에서는 OFDM을 이용(Orthogonal frequency division multiplexing)

주파수를 더 작은 주파수로 Orthogonal 하게(대충 간섭 안일으키게) 쪼갠다.  

## p.31

wifi 20MHz -56개로 나눔, 4개는 안씀 -> 52개의 subcarrier: 312.5kHz

Symbol duration: 3.6us -> 네모하나는 3.2us인데 guardinterval(0.4, 0.8)가 더해짐

## p.32

40MHz를 쓰게 해주면 대충 subcarrier 개수 늘어남

## p.33

전송속도 계산 -> 다음시간에







2024/05/09

## p.31

pilot: 이미 알려진 data pattern -> 수신자는 어떻게 신호가 왜곡 되는지 파악 -> decoding에 활용

## p.32

40MHz가 되면 subcarrier 2배보다 조금 많아짐

Symbol duration: 3.2us + guard interval(0.4로 가정) = 3.6us -> 1초에 277,777개 가능

subcarrier: 108

64QAM & 5/6

-> 1초에 108 * 277777 * 5 -> 대충 1억 5천 -> 150Mbps

여기에 4 * 4 MIMO -> 150 * 4 = 600Mbps

802.11n: N(4, HT), AC(5, VHT), AX(6, HE), BE(), BN()



