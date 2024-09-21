# ch.9

2024/05/14

## p.2

Layer가 있어서 Multi hop가 가능하다

## p.5

통신할라면 무언가 공통점은 있어야 한다 -> Layer 3 IP를 하나의 프로토콜로 통일

## p.6

전화를 걸고 받는 과정 : connection setup

connectionless: 택배보내는 것, 보내기 전에 막 약속하고 보내는 건 아님, 걍 보내고 못 받으면 알빠노

Best-effort: (부정적, 반대말은 guaranteed) -> 보장못한다(손실, 순서, 중복, 시간)

## p.7

### Packet Format

Header(packet 앞에 붙음)

한줄당 4byte * 5 줄 = 20 byte

Source IP address: 보내는 놈

Destination IP address: 이게 젤 중요, 받는 놈

## p.8

wireshark : 패킷 캡쳐 프로그램 -> 현재 뭘 보내고 받고 있는지 출력





2024/05/16

## p.7

frame: Layer 2

packet(datagram): Layer 3

segment: Layer 4(TCP/UDP)

datagram: Layer 4

IP Packet : IP header(최소 20byte + option) + data(payload)

## p.8

### IP header

VER: IPv4 or IPv6 -> 4, 6

HLEN: header length -> 단위가 4byte임(Header의 크기는 4의 배수) -> 0101 * 4 = 20 byte라는 뜻

## p.10

### Service class

8 bit

Precedence: 중요도(0~7) -> 통신사 정책에 따라 다르다.

D: delay를 줄이는게 중요하다 -> 실시간 통신 등

T: throughput

R: reliability, 빨리안가도 반드시 가야함

C: cost

## p.13

service class revised

DSCP: 6 bit, 다양한 타입과 우선순위를 나눠놓음

ECN: 2 bit, 병목현상 발생시 알려주기 위해

## p.15

### Total length

16 bit

total length(16bit): packet length (header + data)

## p.17

### Time to live

8 bit

TTL: 수명 -> 라우터를 하나 거칠때마다 1씩 감소, 0이 되면 drop -> 무한루프 방지

혹은 짧은 거리만 전송하고 싶을 때

## p.18

### Protocol

8 bit

상위 protocol 정보: TCP=6, UDP=17

프로토콜 정보를 알면 라우터에서 특정 알고리즘을 실행하는데 사용

## p.19

### Header checksum

16 bit

계산된 값임 -> 받은쪽에서 다시 계산해서 일치하는지 확인

## p.25

time to live = ??

## p.26

### MTU

Maximum Transter unit: layer 2가 요구하는 사이즈가 있단다, 거기까지만 전달

ethernet = 1500

layer 2의 고민: 오류없이 통과 하기

router별로 protocol이 다를 수 있다. -> 

## p.28

### Fragmentation

각자의 fragment에 header 붙임

## p.29

### identification

16 bit

fragmentatino 된거 원레는 같은거였는지 확인

## p.30

### Flag

3 bit

D: 1 & MTU가 안맞음 -> 그냥 버림

M: 내 뒤에 fragment 더있으면 1, 마지막이면 0

## p.31

### Fragmentation offset

13 bit

unit: 8 byte

어디서부터 시작하는 데이터인지

## p.33

받는 놈은 M이 0인거 받으면 다 받았는지 보고 합치기 -> 만약에 하나라도 안왔으면 버림







2024/05/21

## p.39

읽어보기

## p.34

MTU가 중간에 작이질 수 있음 -> 다시 fragment

근데 다시 켜져도 reassembly를 하지는 않음 -> 어차피 나중에 더 쪼갤수도
