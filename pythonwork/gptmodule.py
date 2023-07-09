import openai
f=open("modules.txt","w")

openai.api_key = "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"

s=str(openai.Model.list())
f.write(s)
f.close()