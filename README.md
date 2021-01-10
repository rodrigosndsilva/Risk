# Risk
POO Project


## Data to show in game:

- [x] Year
- [x] Turn
- [x] Last luck factor generated
- [x] Conquered territories (name, resistance, production in the current turn)
- [x] Other territories in the world that have not yet been conquered (name, resistance)
- [x] Products (value in warehouse, maximum value, production in the current shift)
- [x] Gold (value in warehouse, maximum value, production in the current shift)
- [x] Military strength (current value, maximum value)
- [x] Existing technologies (name, price, objective summary, acquired / not acquired)
- [x] Event that will occur (name, summary of effects)
- [x] Final score


## World: 

- [x] Vector of Territories
- [x] Vector of Empire
- [x] Vector of Events


## Empire: 

- [x] Vector of owned Territories
- [x] Vector of Tecnologies


## Territories: 

- [x] Plain
- [x] Mountain
- [x] Fortress
- [x] Mine
- [x] Dine
- [x] Castle
- [x] Refuge
- [x] Fishing


## Tecnologies:

- [x] Drones
- [x] Missiles
- [x] Defenses
- [x] Exchange
- [x] Bank


## Events:

- [x] AbandonatedResource
- [x] Invasion
- [x] Alliance


## Commands:

- [x] load <FileName> - Runs a set of configuration commands in FileName, one per line. 
- [x] create <type> <n> - Add to the world n territories of a certain type (example: mine, refuge, for a territory of the Mina type or Refugio type) 
- [x] conquer <name> - Give the empire the order to acquire a certain territory this turn as long as it is available in the world. The name parameter indicates the name of the territory to be conquered (plain1, dune3, etc.). 
- [x] pass - This turn does not intend to conquer any territory. 
- [x] moregold - gets 1 more gold, losing 2 of products; if you do not have 2 products this exchange is not possible 
- [x] moreprod - you get 1 more product, losing 2 gold; if you do not have 2 gold this exchange is not possible 
- [x] moremilitary - buy a military unit: reduce one product unit and one gold unit to obtain an additional military force unit, as long as the military force does not exceed the maximum possible value. 
- [x] acquire <type> - Gives the empire an order to acquire a certain technology. The type parameter indicates which technology to buy (drone, missile, etc.). All the rules previously described are followed here: if it is possible to acquire such an object, its cost is deducted from the empire's existing resources. This new acquisition will be effectively applied to the empire in the corresponding phase of the shift. 
- [x] list <name> - Get information about the game, both globally and only from a specific territory if your name is indicated as a parameter 
- [x] listall - List all information
- [x] next - Finishes the command collection phase and triggers the necessary actions at each stage
- [ ] save <name> - Record the game status in memory, associating it with a name. This action consists of making a kind of savegame for memory, allowing the player to keep in memory several snapshots of the game, corresponding to different moments, allowing him at any time to recover one of those moments. The game remains active, but the copy made to memory will no longer be affected by the commands that have been written since then. 
- [ ] active <name> - Retrieves a given game state in memory, identified by the name indicated, and loads it. The recovered game becomes what is in effect: the commands start to act on it. 
- [ ] delete <name> - Deletes from memory a given game state previously recorded and associated with the specified name. 
- [x] take <qual> <name> - Assault a certain territory or technology as long as it is available. The parameter can be terr –territory or techno-technology. The name parameter indicates the name of the territory or technology. This command is only for DEBUG, with no rules for its acquisition being followed or even the associated cost applied. This command takes effect immediately, there is no need to wait for the corresponding phase. 
- [x] modify <gold | prod> N - Modify the empire data: the amount of gold in the vault or number of units of products to have in warehouses. This command is mainly for DEBUG (for testing and demonstration purposes) 
- [x] fevent <event-name> - forces the occurrence of an event indicated by its name, as described in the list indicated above. This command is for DEBUG and test/evaluation.
- [x] quit - closes the game correctly.
- [x] help - shows all commands.


