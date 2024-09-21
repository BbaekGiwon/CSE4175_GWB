# ch.5

2024/04/11

## p.3

framing, flow error control

## p.5

### Framing

데이터를 어떻게 해석해야 하는가? -> frame(meaningful block of data) 단위로 끊어 읽기

## p.7

frame이 크면 -> 에러잘남 & flow control 어려움

## p.8

* Fixed-size: 크기고정 -> 안알려줘도 되나 적게 보내고 싶어도 정해진 만큼 보내야해서 비효율적이다.
* Variable-size: 크기달라서 알려줘야함

## p.11

### Variable-size Framing

- Flag: 시작-끝 둘다 flag |시작flag + 길이 알려주기
- Header
- Trailer
- Data/payload

-> 이게 Frame Structure

## p.13

flag 패턴이 payload에 나오면 어떻게 되는가? -> 방지하기위해 뭔가를 쑤셔넣는다 -> bit stuffing

## p.14

flag에 1이 6개 나오므로 payload에는 1이 6개 못나오게 한다 -> 1이 5개나오면 무조건 0을 추가한다. -> 후에 수신자는 1이 5개 나온뒤 0은 제거한다.





2024/04/16

## p.16

아니 근데 데이터에 flag 패턴 나오면 어카노?

## p.17

### Byte stuffing

escape character 지정

ex) ESC = 7F, Flag = FF

Data: FF 03 37 48 FF 15 7F 20 과 같이 중간에 7F, FF가 나오면 -> 7F 7F, 7F FF 이렇게 해준다 

## p.18

데이터(payload)에 아래와 같이 나타나면

7E -> 7D 5E

7D -> 7D 5D

이렇게 바꿔준다.

ex) 5D 7E 5D 7D 5E -> 7E (5D 7E 5D 7D 5E) 7E -> payload만 추출 -> (5D 7D 5E 5D 7D 5D 5E)

## p.19

Data and Pad: 데이터 들어가는 자리 (46-1500 byte)수용 -> 46 보다 적으면 padding을 통해 채운다.

data 앞에 붙어있는 것들 = Header

FCS = Trailer

## p.20

Ethernet -> 여려명이 연결되어 있음 -> 뭐 전송하면 다 받긴 받음 -> 근데 header 보고 내꺼 아니다 싶으면 무시

preamble 1010101 -> 7회 반복 -> 7번 동안 캐치하도록 기다리는 거임

SFD 10101011 -> 마지막에 한번 -> 여기부터가 데이터 시작한다고 알려주는거

중간에 캐치 = synchronize

## p.21

Destination MAC address: 기기마다 있는 물리적 주소

Source MAC address: 보내는 놈 주소



Application(5,6,7) - Applicaton Header를 붙임 -> App_Header/Data

Transport(TCP)(4) - TCP header 붙임 -> TCP_Header/App_Header/Data

Network(IP)(3) - IP Header 붙임 -> IP_Header/CP_Header/App_Header/Data

Data Link(Ethernet)(2) -> Header & FCS 붙임 -> ETH_Header/IP_Header/CP_Header/App_Header/Data

physical에서 Header를 다띠어가지고 읽어옴

## p.23

Flow Control - 기기 마다 다 속도가 다르다. 보내는 놈은 빠른데 처리하는 놈이 느릴 수도 있다. 그럼 와도 못받음 (buffer 꽉차면) -> 그럼 천천히 보내라고 해야함 = Flow Control

## p.24

수신 buffer에 넣어놓고 처리하는 중 -> 천천히 보내라고 하는

## p.25

Error 검출 - 송신자에게 다시 보내달라고 하는거

## p.26

### ACK

ack: 감사의 글?, 답장(데이터 잘 받았다는)

데이터를 보내면 상대방에게 잘 받았다고 알려줘야함

## p.27

ACK는 flow, error control 둘다에 쓰인다.

-읽

## p.31

Error case

- 아에 못 받음 or 받았는데 오류임 -> ACK 못 보냄
- 받고 ACK 가 제대로 안감

## p.33

retransmition: T 초 기다리고 ACK 안왔으면(timeout) 다시 보냄

## p.34

RTT: Round Trip time = 왕복시간

* 1트 실패 -> 다시 보냄 -> 2트 성공 -> ACK 받음
* 1트 성공 -> ACK 실패 -> 다시보냄 -> 2트 성공 -> ACK 받음
* 1트 성공 -> ACK 전송 -> 안오는 줄 알고 다시보냄 -> ACK 수신-> 2트 성공 ->  ACK 받음

-> time out 시간이 중요하다.

## p.37

트래픽에 따라 통신 시간은 매번 다르다 -> 허나 그렇게까지 차이가 나지는 않는다.

RTT = Transmission time + Propagation time + Transmission time(ACK) + Propagation time(ACK) + Processing time(sender & receiver)

-> 오차 나는 구멍이 많다 -> T = RTT + margin -> margin을 둔다

## p.39

p.39 ~ 42 대충 훑

## p.43

4가지가 수신자 입장에서는 같다. -> 그냥 오면 ACK 보냄 -> 순서 만으로는 새건지 옛것인지 구분이 안되므로 추가 방법 필요 -> sequence number

## p.44

sequence number 이것도 공간 낭비임 -> 고로 1bit만 사용할거임

수신자 입장에서 frame(0), frame(0) -> 이렇게 두개 같은 번호 받으면 중복이라고 판단

ACK(1) = 1번 주세요(0번 받았으니)

## p.46

~p.50 대충 훑

## p.51

### Stop-and-Wait

bandwidth = 1Mbps

Rtt = 20ms

frame size = 1000 bits

50bits per ms -> 50,000 bits per sec -> 50Kbps

그러기에 남아돈다 -> 굳이 안기다리고 미리미리 보내는 방법도 존잰

