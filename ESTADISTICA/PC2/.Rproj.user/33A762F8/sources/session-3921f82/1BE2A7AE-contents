#PREGUNTA A
# Definicion de las funciones de distribucion acumulada 
FAX1 = function(x) { (1 - exp(-(x/11)^11)) }
FAX2 = function(x) { exp(-(10/x)^10)}

# Definición de las funciones de distribución acumulada inversa para cada componente
FX1_inv <- function(u) -11 * log(1 - u)
FX2_inv <- function(u) 10 / log(1/u)

# Generación de 10,000 números aleatorios uniformes entre 0 y 1
u_C1 <- runif(10000)
u_C2 <- runif(10000)

# Transformación inversa para obtener los valores simulados de duración para C1 y C2
C1_val <- FX1_inv(u_C1)
C2_val <- FX2_inv(u_C2)

# Graficar las distribuciones de duración de C1 y C2
par(mfrow = c(1, 2))  
hist(C1_val, freq = FALSE, col = "lightblue", main = "Componente C1",
     xlab = "Duración (miles de horas)", ylab = "Densidad")
curve(FAX1, add = TRUE, col = "red", lwd = 2)

hist(C2_val, freq = FALSE, col = "lightgreen", main = "Componente C2",
     xlab = "Duración (miles de horas)", ylab = "Densidad")
curve(FAX2, add = TRUE, col = "blue", lwd = 2)

# Añadir leyendas
legend("topright", legend = c("Distribución real", "Distribución simulada"),
       col = c("red", "blue"), lty = 1, lwd = 2)


#PREGUNTA B
# Definicion de la funcion de distribucion acumulada FX3  
FAX3 = function(x) {1 - (1 / ((1 + (x / 8)^20)^2))}

# Definición de la funcion de distribución acumulada inversa para FX3
FX3_inv = function(u) 8 * ((1/u - 1)^(-1/20) - 1)

# Generación de 10,000 números aleatorios uniformes para C3
u_C3 = runif(10000)

# Transformación inversa para obtener los valores simulados de duración para C3
C3_val = FX3_inv(u_C3)

# Simulación del tiempo de duración del subsistema formado por C1 y C2
subSistema_val = pmin(C1_val, C2_val)

# Gráfico comparativo de las distribuciones de C3 y el subsistema C1-C2
par(mfrow = c(1, 2))  

# Histograma y función de distribución acumulada de C3
hist(C3_val, freq = FALSE, col = "lightblue", main = "Componente C3",
     xlab = "Duración (miles de horas)", ylab = "Densidad")
curve(FAX3, add = TRUE, col = "red", lwd = 2)

# Histograma y función de distribución acumulada del subsistema C1- C2
hist(subSistema_val, freq = FALSE, col = "lightgreen", main = "Subsistema C1- C2",
     xlab = "Duración (miles de horas)", ylab = "Densidad")
curve(FAX1, add = TRUE, col = "blue", lwd = 2) 

# Añadir leyendas
legend("topright", legend = c("Distribución real", "Distribución simulada"),
       col = c("red", "blue"), lty = 1, lwd = 2)


#PREGUNTA C
# Simulación de 10,000 valores aleatorios para el tiempo de duración del sistema Y
Y_val <- pmax(pmin(C1_val, C2_val), C3_val)

# Gráfico de la distribución del tiempo de duración del sistema Y
par(mfrow = c(1, 1))  
hist(Y_val, freq = FALSE, col = "lightblue", main = "Tiempo de Duración del Sistema",
     xlab = "Duración (miles de horas)", ylab = "Densidad")

# Calculo de la media de Y
media_Y <- mean(Y_val)

# Cálculo de los cuantiles aproximados y0.025 y y0.975
cuantiles_Y <- quantile(Y_val, c(0.025, 0.975))

# Añadir líneas verticales para indicar la media y los cuantiles en el gráfico
abline(v = media_Y, col = "red", lty = 2)
abline(v = cuantiles_Y, col = "green", lty = 2)

# Mostrar la media y los cuantiles en la leyenda
legend("topright", legend = c("Media", "Cuantiles"),
       col = c("red", "green"), lty = 2, lwd = 2,
       title = "Estadísticas",
       text.col = "black",
       inset = 0.05,
       bg = "white",
       cex = 0.8)

# Imprimir los resultados
cat("La media del tiempo de duración del sistema Y es:", media_Y, "\n")
cat("El cuantil y0.025 aproximado es:", cuantiles_Y[1], "\n")
cat("El cuantil y0.975 aproximado es:", cuantiles_Y[2], "\n")

#PREGUNTA D
# Leer los datos del archivo tiempo.csv
datos <- read.csv("tiempo.csv")

# Calcular los cuantiles muestrales
cuantiles_muestrales <- quantile(datos$tiempo, probs = seq(0.02, 0.98, by = 0.02))

# Calcular los cuantiles poblacionales 
cuantiles_poblacionales <- quantile(Y_val, probs = seq(0.02, 0.98, by = 0.02))

# Gráfico de cuantiles
plot(cuantiles_muestrales, cuantiles_poblacionales,
     type = "b", pch = 19, col = "blue",
     xlab = "Cuantiles muestrales", ylab = "Cuantiles poblacionales",
     main = "Gráfico de Cuantiles")

# Agregar una línea diagonal para facilitar la comparación
abline(0, 1, col = "red", lty = 2)

# Añadir leyendas
legend("topleft", legend = "Identidad", col = "red", lty = 2, bty = "n")
