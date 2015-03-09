
class Action
    def initialize(funct)
        @funct = funct
        @Q = 0
    end
    
    def call(state)
        @funct.call(state)
    end
    
    def getQ; @Q end
        
    def setQ(q); @Q = q end
end

class State
    def initialize()
        @actions = Array.new
        @lastAction = :none
    end

    def addAction(action)
        @actions.push(action)
    end
    
    def getMaxQ
        max = :none
        for a in @actions
            if max == :none
                max = a.getQ
            elsif a.getQ > max
                max = a.getQ
            end
        end
        return max
    end

    def update(reward, rate, nextQ)
        @lastAction.setQ(@lastAction.getQ +
        rate * (reward + nextQ - @lastAction.getQ))
        @lastAction = :none
    end
    
    def chooseAction
        @lastAction = @actions[0]
        return @actions[0]
    end
end

class Qlearn
    def initialize(state, rate)
        @state = state
        @rate = rate
    end
    
    def update(newState, reward)
        @state.update(reward, @rate, newState.getMaxQ)
        @state = newState
    end
    
    def act
        action = @state.chooseAction
        newState, reward = action.call(@state)
        update(newState, reward)
    end
end

def fucnta(state)
    if state == :a
        return [state, 2]
    else
        return [state, 4]
    end
end

n = Action.new(method(:fucnta))
j = State.new
j.addAction(n)
b = Qlearn.new(j, 0.1)
b.act
puts n.getQ
