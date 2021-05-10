#global values
symNord_num = 10000
add_order_num = 50000000
id_counter = symNord_num

def create_symbols_and_orderbooks(output):
	counter = 0

	char1 = ord('A')
	char2 = ord('A')
	char3 = ord('A')
	char4 = ord('A')

	for i in range(symNord_num):
		name = chr(char4) + chr(char3) + chr(char2) + chr(char1)
		output.write("add symbol "+ str(i) +" "+ name +"\n")
		output.write("add book "+ str(i) +"\n")

		counter += 1
		if(counter % (26*26*26) == 0):
			char4 += 1
			char3 = ord('A')
			char2 = ord('A')
			char1 = ord('A')
		elif(counter % (26*26) == 0):
			char3 += 1
			char2 = ord('A')
			char1 = ord('A')
		elif(counter % 26 == 0):
			char2 += 1
			char1 = ord('A')
		else:
			char1 += 1

def delete_symbols_and_orderbooks(output):
	for i in range(symNord_num):
		output.write("delete book "+ str(i) +"\n")
		output.write("delete symbol "+ str(i) +"\n")
		

def create_many_buy_limit_orders_to_one_fok_limit_sell(output):
	global id_counter

	symbol = 0
	quantity_buy = 10
	price = 10
	for i in range(add_order_num):
		output.write("add limit buy "+ str(id_counter)+" " + str(symbol)+" " + str(price)+" " + str(quantity_buy) +"\n")
		id_counter += 1


	quantity_sell = add_order_num * 10
	output.write("add fok limit sell "+ str(id_counter)+" " + str(symbol)+" "+ str(price)+" " + str(quantity_sell) +"\n")
	id_counter += 1


def create_one_sell_limit_order_to_many_market_buys(output):
	global id_counter

	symbol = 5678
	quantity_sell = add_order_num * 10
	price = 10
	output.write("add limit sell "+ str(id_counter)+" " + str(symbol)+" "+ str(price)+" " + str(quantity_sell) +"\n")
	id_counter += 1

	quantity_buy = 10
	for i in range(add_order_num):
		output.write("add market buy "+ str(id_counter)+" " + str(symbol)+" " + str(quantity_buy) +"\n")
		id_counter += 1
	

def create_trailing_orders_that_get_updated_and_then_matched(output):
	global id_counter

	#this
	symbol = 9999
	quantity_buy1 = 20
	price = 50
	output.write("add limit buy "+ str(id_counter)+" " + str(symbol)+" "+ str(price)+" " + str(quantity_buy1) +"\n")
	id_counter += 1

	stop_price = 0
	quantity_sell = 10
	trailling_distance = 10
	trailing_step = 5
	price1 = 0
	for i in range(add_order_num):
		output.write("add trailing stop sell "+ str(id_counter)+" " + str(symbol)+" " + str(stop_price)+" " + str(quantity_sell)+" " + str(trailling_distance)+" " + str(trailing_step) +"\n")
		#output.write("add trailing stop-limit sell "+ str(id_counter)+" " + str(symbol)+" " + str(stop_price)+" "+ str(price1)+" "+ str(quantity_sell)+" " + str(trailling_distance)+" " + str(trailing_step) +"\n")
		id_counter += 1

	#is matched 10 quantity by this and limit buy leaves 10 quantity so that the trailing orders be updated setting stop-price at 40 for trailing orders 
	output.write("add market sell "+ str(id_counter)+" " + str(symbol)+" " + str(quantity_sell) +"\n")
	id_counter += 1


	#this 2 match each other and and limit buy leaves 10 quantity so that the trailing orders be updated setting stop-price at 70 for trailing orders 
	price2 = 80
	output.write("add limit buy "+ str(id_counter)+" " + str(symbol)+" "+ str(price2)+" " + str(quantity_buy1) +"\n")
	id_counter += 1
	output.write("add market sell "+ str(id_counter)+" " + str(symbol)+" " + str(quantity_sell) +"\n")
	id_counter += 1


	#this 2 match each other as well as all trailing stop-limit orders at price 30
	price3 = 30
	quantity_buy = add_order_num * 10
	quantity_sell1 = 20
	output.write("add limit buy "+ str(id_counter)+" " + str(symbol)+" "+ str(price3)+" " + str(quantity_buy) +"\n")
	id_counter += 1
	output.write("add market sell "+ str(id_counter)+" " + str(symbol)+" "+ str(quantity_sell1) +"\n")
	id_counter += 1


def reduce_orders(output):
	global id_counter

	symbol = 0
	quantity_buy = add_order_num * 10
	price = 10
	output.write("add limit buy "+ str(id_counter)+" " +str(symbol)+" "+ str(price)+" " + str(quantity_buy) +"\n")
	id_counter += 1

	reduce_by_quantity = 1
	for i in range(add_order_num):
		output.write("reduce order "+ str(id_counter)+" "+ str(reduce_by_quantity) +"\n")
		id_counter += 1
		

def modify_mitigate_replace_orders(output):
	global id_counter

	symbol = 0
	price_1 = 10
	quantity_1 = 10
	output.write("add limit buy "+ str(id_counter)+" "+ str(symbol)+" " +str(price_1)+" " + str(quantity_1) +"\n")
	id_counter += 1

	price_2 = 5
	quantity_2 = 5
	for i in range(add_order_num):
		if(i%2 == 1):
			#output.write("modify order "+ str(id_counter)+" "+ str(price_2)+" "+ str(quantity_2) +"\n")
			#output.write("mitigate order "+ str(id_counter)+" "+ str(price_2)+" "+ str(quantity_2) +"\n")
			output.write("replace order "+ str(id_counter-1)+" "+ str(id_counter)+" "+ str(price_2)+" "+ str(quantity_2) +"\n")
		else:
			#output.write("modify order "+ str(id_counter)+" "+ str(price_1)+" "+ str(quantity_1) +"\n")
			#output.write("mitigate order "+ str(id_counter)+" "+ str(price_1)+" "+ str(quantity_1) +"\n")
			output.write("replace order "+ str(id_counter-1)+" "+ str(id_counter)+" "+ str(price_1)+" "+ str(quantity_1) +"\n")	
		id_counter += 1


def stop_limit_orders_activated_at_second_limit_buy(output):
	global id_counter

	#this
	symbol = 4
	quantity_check = 10
	price1 = 80
	output.write("add limit buy "+ str(id_counter)+" " + str(symbol)+" "+ str(price1)+" " + str(quantity_check) +"\n")
	id_counter += 1

	#them
	stop_price = 50
	quantity_sell = 10
	price = 40	#will become limit sell order with price 40
	for i in range(add_order_num):
		#output.write("add stop sell "+ str(id_counter)+" " + str(symbol)+" " + str(stop_price)+" "+ str(quantity_sell)+"\n")							#activates to MARKET order
		output.write("add stop-limit sell "+ str(id_counter)+" " + str(symbol)+" " + str(stop_price)+" "+ str(price)+" "+ str(quantity_sell)+"\n")		#activates to LIMIT order
		id_counter += 1

	#activates and matches them
	price2 = 40
	quantity_buy = add_order_num * 10
	output.write("add limit buy "+ str(id_counter)+" " + str(symbol)+" "+ str(price2)+" " + str(quantity_buy) +"\n")
	id_counter += 1

	#activates this
	output.write("add market sell "+ str(id_counter)+" " + str(symbol)+" "+ str(quantity_check) +"\n")
	id_counter += 1



def main():
	with open('scenario.txt', 'w') as out_file:
		out_file.write("enable matching\n")

		create_symbols_and_orderbooks(out_file)

		create_many_buy_limit_orders_to_one_fok_limit_sell(out_file)

		create_one_sell_limit_order_to_many_market_buys(out_file)

		create_trailing_orders_that_get_updated_and_then_matched(out_file)

		#reduce_orders(out_file)
		#modify_mitigate_replace_orders(out_file)

		stop_limit_orders_activated_at_second_limit_buy(out_file)

		delete_symbols_and_orderbooks(out_file)


main()