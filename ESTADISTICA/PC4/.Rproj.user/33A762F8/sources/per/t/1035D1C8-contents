datos = read.csv("consumosal.csv")
descr(datos,stats=c("n.valid","mean","sd"))
#Parte A
#Gamma
#Función de verosimilitud
logLikGamma = function(theta,x){
  alpha= theta[1]
  beta = theta[2]
  -sum(dgamma(x,alpha,1/beta,log = TRUE))
}
#Estimacion usando nlminb
fit_gama = nlminb(
  start= c(20,0.1),
  objective = logLikGamma,
  lower= c(0,0),
  upper= c(Inf,Inf),
  x= datos$pre
)
fit_gama$par
fit_gama$objective
-fit_gama$objective


#Normal
# Función de verosimilitud
logLikNormal = function(params) {
  mean = params[1]
  sd = params[2]
  -sum(dnorm(datos$pre, mean=mean, sd=sd, log=TRUE))
}
# Estimación usando optim
fit_normal = optim(
  c(mean(datos$pre), sd(datos$pre)), 
  logLikNormal, method="L-BFGS-B", 
  lower=c(-Inf, 0.0001))
fit_normal$par

#Log-Normal
# Función de verosimilitud
logLikLogNormal <- function(params) {
  meanlog = params[1]
  sdlog = params[2]
  -sum(dlnorm(datos$pre, meanlog=meanlog, sdlog=sdlog, log=TRUE))
}

# Estimación usando optim
fit_lognormal = optim(
  c(0, 1), logLikLogNormal, 
  method="L-BFGS-B", 
  lower=c(-Inf, 0.0001))
fit_lognormal$par

#Weibull
# Función de verosimilitud
logLikWeibull = function(theta,x){
  alpha = theta[1]
  beta = theta[2]
  -sum(dweibull(x,alpha,beta,log = TRUE))
}

# Estimación usando nlminb
fit_weibull = nlminb(
  start= c(1,1),
  objective = logLikWeibull,
  lower= c(0,0),
  upper = c(Inf,Inf),
  x = datos$pre
)
fit_weibull$par
-fit_weibull$objective

fit_gama$par
fit_gama$objective
fit_normal$par
fit_normal$value
fit_lognormal$par
fit_lognormal$value
fit_weibull$par
fit_weibull$objective

#log-verosimilitud para luego comparar
logLik_values = c(Gamma = -fit_gama$objective, 
                   Normal = -fit_normal$value, 
                   LogNormal = -fit_lognormal$value, 
                   Weibull = -fit_weibull$objective)
logLik_values
#Calcular el AIC para luego comparar
AIC_values = c(
  aic_Gamma = -2*-fit_gama$objective+2*2,
  aic_Normal = -2*-fit_normal$value+2*2,
  aic_LogNormal = -2*-fit_lognormal$value+2*2,
  aic_Weibull = -2*-fit_weibull$objective+2*2
)
AIC_values
#Grafico de cuartiles
#Gamma
alpha_est = fit_gama$par[1]
beta_est = fit_gama$par[2]
qqplot_gamma = function(data, alpha, beta) {
  # Cuantiles teóricos de la distribución Gamma
  Cuantiles_teoricos_G = qgamma(ppoints(length(data)), shape = alpha, scale = beta)
  # Gráfico Q-Q
  qqplot(
    Cuantiles_teoricos_G, 
    data, main = "Gráfico de cuantiles de Gamma", 
    xlab = "Cuantil Poblacional", 
    ylab = "Cuantil Muestral", pch = 19)
  qqline(data, distribution = function(p) qgamma(p, shape = alpha, scale = beta), col = "red")
}
qqplot_gamma(datos$pre, alpha_est, beta_est)

#Normal
mean_est = fit_normal$par[1]
sd_est = fit_normal$par[2]
qqplot_normal = function(data, mean, sd) {
  # Cuantiles teóricos de la distribución Normal
  Cuantiles_teoricos_N = qnorm(ppoints(length(data)), mean=mean, sd=sd)
  # Gráfico Q-Q
  qqplot(
    Cuantiles_teoricos_N, 
    data, main = "Gráfico de cuantiles de Normal", 
    xlab = "Cuantil Poblacional", 
    ylab = "Cuantil Muestral", pch = 19)
  qqline(data, distribution = function(p) qnorm(p, mean=mean, sd=sd), col = "red")
}
qqplot_normal(datos$pre, mean_est, sd_est)

#Log-Normal
meanlog_est = fit_lognormal$par[1]
sdlog_est = fit_lognormal$par[2]
qqplot_lognormal = function(data, meanlog, sdlog) {
  # Cuantiles teóricos de la distribución Log-Normal
  Cuantiles_teoricos_L = qlnorm(ppoints(length(data)), meanlog=meanlog, sdlog=sdlog)
  # Gráfico Q-Q
  qqplot(
    Cuantiles_teoricos_L, 
    data, main = "Gráfico de cuantiles de Log-Normal", 
    xlab = "Cuantil Poblacional", 
    ylab = "Cuantil Muestral", pch = 19)
  qqline(data, distribution = function(p) qlnorm(p, meanlog=meanlog, sdlog=sdlog), col = "red")
}
qqplot_lognormal(datos$pre, meanlog_est, sdlog_est)

#Weibull
alpha_est = fit_weibull$par[1]
beta_est = fit_weibull$par[2]
qqplot_weibull = function(data, alpha, beta) {
  # Cuantiles teóricos de la distribución Weibull
  Cuantiles_teoricos_W = qweibull(ppoints(length(data)), alpha, beta)
  # Gráfico Q-Q
  qqplot(
    Cuantiles_teoricos_W, 
    data, main = "Gráfico de cuantiles de Weibull", 
    xlab = "Cuantil Poblacional", 
    ylab = "Cuantil Muestral", pch = 19)
  qqline(data, distribution = function(p) qweibull(p, alpha, beta), col = "red")
}
qqplot_weibull(datos$pre, alpha_est, beta_est)

#PARTE B
hipertension_data = subset(datos, pre > 120)
hipertension_data$diff = hipertension_data$post - hipertension_data$pre
hipertension_data$diff
t.test(x=hipertension_data$diff,conf.level = 0.95)
#PARTE C
meanlog_est = fit_lognormal$par[1]
sdlog_est = fit_lognormal$par[2]
#Datos
media_poblacion = exp(meanlog_est+(sdlog_est^2)/2)
numSimulaciones = 1000
n = 40
contador=0 # contador para verificar cuantos intervalos contiene la media
#Realizar Simulaciones
for(i in 1:numSimulaciones){
  #muestra de tamaño elegido
  muestra = rlnorm(n,meanlog_est,sdlog_est)
  # Calcular el intervalo de confianza al 95% 
  intervalo = t.test(muestra,conf.level = 0.95)
  lim_sup = intervalo$conf.int[2]
  lim_inf = intervalo$conf.int[1]
  #Verificacion
  if(media_poblacion >= lim_inf && media_poblacion <= lim_sup){
    contador = contador+1
  }
}
proporcion = contador / numSimulaciones
media_poblacion
contador
proporcion

