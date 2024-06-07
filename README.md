Deep Blue: Monitoramento de pH e Temperatura da Água em Rios e Praias
Este projeto foi desenvolvido para monitorar a qualidade da água em rios e praias, medindo o pH e a temperatura. Ele visa fornecer informações críticas para a avaliação ambiental e ajudar a garantir a saúde dos ecossistemas aquáticos.

Sumário
Introdução
Componentes Necessários
Circuito e Conexões
Instalação e Configuração
Funcionamento do Sistema
Importância do pH e da Temperatura da Água
Licença
Referências
Introdução
A qualidade da água em ambientes naturais como rios e praias é essencial para a preservação da biodiversidade e para o uso humano. O monitoramento constante desses parâmetros ajuda a identificar possíveis problemas de contaminação e a tomar ações corretivas. Este projeto utiliza um sensor de temperatura e um potenciômetro (simulando um sensor de pH) para medir e exibir esses valores, com indicações visuais através de LEDs e alertas sonoros.

Componentes Necessários
1 x Arduino Uno ou compatível
1 x Sensor de temperatura Dallas DS18B20
1 x Módulo OneWire
1 x Potenciômetro (para simular o sensor de pH)
1 x Display LCD 16x2
1 x Buzzer
3 x LEDs (Vermelho, Amarelo e Verde)
Resistores para os LEDs
Fios de conexão
Protoboard
Circuito e Conexões
Conexões dos Componentes
Sensor de Temperatura DS18B20

VCC: 5V
GND: GND
Data: Pino 3 do Arduino
Display LCD 16x2

RS: Pino 13
E: Pino 12
D4: Pino 7
D5: Pino 6
D6: Pino 5
D7: Pino 4
VCC: 5V
GND: GND
Potenciômetro (simulando sensor de pH)

Pino central (sinal): A0 do Arduino
Outros dois pinos: 5V e GND
Buzzer

Positivo: Pino 2 do Arduino
Negativo: GND
LEDs

Vermelho: Pino 11
Amarelo: Pino 10
Verde: Pino 9
Anodo de cada LED: 5V através de resistores apropriados
Catodo de cada LED: pinos designados do Arduino
Instalação e Configuração
Software Necessário
Arduino IDE (para programação do Arduino)
Biblioteca OneWire (para comunicação com o sensor DS18B20)
Biblioteca DallasTemperature (para facilitar a leitura do sensor de temperatura)
Passos para Configuração
Instale o Arduino IDE:
Baixe e instale a última versão do Arduino IDE em arduino.cc.

Adicione Bibliotecas:
No Arduino IDE, vá para Sketch -> Include Library -> Manage Libraries.... Procure e instale as bibliotecas OneWire e DallasTemperature.

Monte o Circuito:
Siga o esquema de conexões descrito acima para conectar os componentes ao Arduino.

Carregue o Código:
Abra o código fornecido no Arduino IDE e faça o upload para o seu Arduino.
Funcionamento do Sistema
O sistema mede a temperatura e o pH da água e exibe os valores em um display LCD. Dependendo das leituras, LEDs e alertas sonoros são ativados para indicar as condições da água.

Temperatura:

Muito quente: > 25°C
Temperatura ambiente: 20°C - 25°C
Muito frio: < 20°C
pH:

Condições ideais: pH entre 6 e 9
Ácido: pH < 6
Básico: pH > 9
O sistema atualiza as leituras a cada 2 segundos.

Importância do pH e da Temperatura da Água
pH da Água
O pH é uma medida da acidez ou basicidade da água. Em rios e praias, um pH balanceado é crucial para a saúde dos ecossistemas aquáticos. Valores de pH muito baixos ou muito altos podem ser indicativos de poluição ou desequilíbrios ecológicos, afetando negativamente a flora e fauna aquáticas.

pH baixo (ácido): Pode ocorrer devido a escoamentos ácidos ou poluição industrial. Níveis muito baixos de pH podem causar danos aos peixes e outros organismos aquáticos.
pH alto (básico): Pode ser causado por escoamentos alcalinos ou presença de certas algas. Níveis muito altos de pH também podem ser prejudiciais para a vida aquática.
Temperatura da Água
A temperatura da água influencia diretamente a solubilidade do oxigênio e a taxa metabólica dos organismos aquáticos. Mudanças significativas na temperatura podem causar estresse aos organismos e alterar a dinâmica do ecossistema.

Água muito quente: Pode diminuir a quantidade de oxigênio dissolvido na água, causando estresse aos peixes e outros organismos.
Água muito fria: Pode retardar os processos metabólicos e afetar negativamente as populações aquáticas que dependem de temperaturas mais altas.
O monitoramento regular dessas condições ajuda na manutenção de ambientes aquáticos saudáveis e na detecção precoce de possíveis problemas.

Licença
Este projeto é distribuído sob a licença MIT. Sinta-se livre para usar, modificar e distribuir o código conforme necessário.

Referências
Portal da Qualidade das Águas - Agência Nacional de Águas e Saneamento Básico (ANA)
Arduino OneWire Library
Arduino DallasTemperature Library